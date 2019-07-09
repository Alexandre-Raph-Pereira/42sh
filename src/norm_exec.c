/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** norm_exec
*/

#include "mysh.h"

int if_forking(tree_t *tree)
{
    if (is_a_builtin(tree->command) == 1)
        return (1);
    if (check_exec(tree->full_command[0], tree->command) == 0)
        return (1);
    return (0);
}

void norm_exec(tree_t *tree, int *pipes_fd, int prev_fd, int r)
{
    exec_redirect(tree, pipes_fd, prev_fd);
    if (r == 2)
        check_next_redirect(tree, &pipes_fd[2], pipes_fd, prev_fd);
}

int is_a_builtin(char *command)
{
    char *builtin[7] = {"setenv", "unsetenv", "cd",
            "echo", "exit", "history", NULL};

    for (int i = 0; builtin[i]; i ++) {
        if (command && my_strcmp(command, builtin[i]) == 0) {
            return (1);
        }
    }
    return (0);
}

int is_executable(char *command) 
{
    char *builtin[2] = {"exit", NULL};

    for (int i = 0; builtin[i]; i ++) {
        if (command && my_strcmp(command, builtin[i]) == 0) {
            return (1);
        }
    }
    return (0);
}

int exec_all(tree_t *tree, all_t *all_thing)
{
    int and = 0;

    if (is_a_builtin(tree->command) == 1) {
        if (is_executable(tree->command) == 1)
            and = exec_builtin(tree->full_command,
                &all_thing->envi, all_thing->history);
        exit(0);
    }
    else
        and = my_exec(tree, all_thing->envi);
    return (and);
}