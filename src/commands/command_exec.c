/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** command_exec
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include "mysh.h"
#include "minishell_struct.h"
#include "my_printf.h"

int exec_simple_command(tree_t *tree, char **env)
{
    int pid = fork();
    int status = 0;

    if (pid == -1)
        return (84);
    if (pid == 0) {
        if (check_bin(tree->full_command[0], tree->full_command[0]) == 0)
            exit(0);
        if (exec_builtin(tree->full_command, &env, NULL))
            return (SUCCESS);
        if (execve(tree->full_command[0], tree->full_command, env) == -1) {
            printf("%s: Exec format error. Wrong Architecture.\n",
                    tree->full_command[0]);
            exit(0);
            return (84);
        }
    }
    waitpid(pid, &status, 0);
    status_gestion(status);
    return (0);
}

int if_redirection(tree_t *tree)
{
    if (tree == NULL)
        return (0);
    if (tree->left != NULL && tree->left->token[0] == '>') {
        return (1);
    }
    if (tree->left != NULL && tree->left->token[0] == '<') {
        if (tree->right && tree->right->left != NULL
            && tree->right->left->token[0] == '>')
            return (2);
        return (1);
    }
    return (0);
}

int exec_commands(tree_t *tree, char ***env, hist_t *history)
{
    while (tree != NULL) {
        if (tree->left && is_redirect_or_pipe(tree->left->token) == true) {
            do_pipes(tree, env, history);
            move_while_pipe(&tree);
        } else
            exec_simple_command(tree, *env);
        tree = tree->right;
    }
    return (0);
}
