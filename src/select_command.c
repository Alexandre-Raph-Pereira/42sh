/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** select_command
*/

#include <stdlib.h>
#include "mysh.h"

void display_tree(tree_t *tree)
{
    while (tree) {
        my_printf("command: %s    ", tree->command);
        my_printf("full command : %s", tree->full_command[0]);
        if (tree->full_command[1] != NULL)
            my_printf(" arg : %s ", tree->full_command[1]);
        if (tree->left)
            my_printf("   token: %s", tree->left->token);
        my_printf("\n");
        tree = tree->right;
    }
}

int count_args(char **args)
{
    int i = 0;

    while (args[i] != NULL)
        i ++;
    return (i);
}

int exec_builtin(char **args, char ***env, hist_t *history)
{
    int (*fnct_ptr[5])(char ***, char **) = {&exec_setenv, &exec_unsetenv,
                                            &cd_function, &my_echo,
                                            &my_exit};
    char *commands[6] = {"setenv", "unsetenv", "cd", "echo", "exit", NULL};
    int status = 0;

    for (int i = 0; commands[i]; i ++)
        if (args[0] && my_strcmp(args[0], commands[i]) == 0) {
            status = fnct_ptr[i](env, args);
            return (status);
        }
    if (args[0] && my_strcmp(args[0], "history") == 0) {
        print_hist(history);
        return (FAIL);
    } if (args[0] && args[0][0] == '!' && args[0][1] != ' ') {
        history = rm_history(history, args[0]);
        return (FAIL);
    }
    return (SUCCESS);
}

char **select_command(char *line, char **env, hist_t *history)
{
    tree_t *tree = NULL;
    int status = 0;

    select_command_check_line(line, &tree, &status, env);
    if (status == 1)
        return (env);
    if (tree->full_command[0] &&
        my_strcmp(tree->full_command[0], "env") == 0) {
        exec_env(env);
        return (env);
    } if (tree->right == NULL && is_a_builtin(tree->full_command[0]) == 1) {
        status = exec_builtin(tree->full_command, &env, history);
        return (env);
    }
    exec_commands(tree, &env, history);
    free_tree(tree);
    return (env);
}
