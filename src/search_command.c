/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_command
*/

#include "mysh.h"

char *concat_command(char *path, char *command)
{
    char *full_path = NULL;
    char *save = NULL;

    full_path = my_strmcat(path, "/");
    save = full_path;
    full_path = my_strmcat(full_path, command);
    free(save);
    return (full_path);
}

char **get_paths(char **env)
{
    char *paths_line = my_getenv(env, "PATH");
    char **paths = NULL;

    if (paths_line == NULL) {
        paths = malloc(sizeof(char *) * 2);
        if (paths == NULL)
            exit(84);
        paths[0] = malloc(sizeof(char) * 1);
        if (paths[0] == NULL)
            exit(84);
        paths[0][0] = '\0';
        paths[1] = NULL;
        return (paths);
    }
    paths = my_str_to_word_array(paths_line, ':');
    if (paths == NULL)
        return (NULL);
    free(paths_line);
    return (paths);
}

int check_if_builtin_or_exist(char *command)
{
    char *builtins[8] = {"setenv", "unsetenv", "cd", "echo", "exit",
                        "history", "env", NULL};
    struct stat st;

    if (stat(command, &st) != -1 && access(command, X_OK) == 0)
        return (SUCCESS);
    for (int i = 0; builtins[i] != NULL; i ++) {
        if (my_strcmp(builtins[i], command) == 0)
            return (SUCCESS);
    }
    if (command && command[0] == '!' && command[1] != ' ')
        return (SUCCESS);
    return (FAIL);
}

char *check_if_on_path(char *command)
{
    if (command[0] != '.' && command[0] != '/') {
        display_error(": Command not found.\n", command);
        return (NULL);
    } if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
            return (my_strcpy(command));
    else if (access(command, F_OK) == 0 && access(command, X_OK) == -1) {
        display_error(": Permission denied.\n", command);
        return (NULL);
    }
    display_error(": Command not found.\n", command);
    return (NULL);
}

char *search_command(char **args, char **env, tree_t *left)
{
    char **exec_paths = get_paths(env);
    char *path = NULL;

    if (check_if_builtin_or_exist(args[0]) == SUCCESS)
        return (args[0]);
    if (left != NULL && (left->token[0] == '>' || left->token[0] == '<'))
        return (args[0]);
    for (int i = 0; exec_paths[i] != NULL; i ++) {
        path = concat_command(exec_paths[i], args[0]);
        if (access(path, F_OK) == 0 && access(path, X_OK) == 0) {
            free_array(exec_paths);
            return (path);
        } else if (access(path, F_OK) == 0 && access(path, X_OK) == -1) {
            display_error(": Permission denied.\n", args[0]);
            free_array(exec_paths);
            return (NULL);
        }
        free(path);
    }
    free_array(exec_paths);
    return (args[0]);
}
