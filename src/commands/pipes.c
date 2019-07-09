/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pipes
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell_struct.h"
#include "mysh.h"

void create_pipes(int *pipes_fd, int pipes_nbr)
{
    for (int i = 0; i < pipes_nbr; i++)
        pipe(&pipes_fd[i * 2]);
}

int check_if_continue(tree_t *tree)
{
    if (tree == NULL)
        return (false);
    if (tree->left && is_redirect_or_pipe(tree->left->token) == false)
        return (false);
    return (true);
}

int is_modifing_env(char *command)
{
    char *builtin[5] = {"setenv", "unsetenv", "cd", "echo", NULL};
    int i = 0;

    for (int i = 0; builtin[i]; i ++) {
        if (command && my_strcmp(command, builtin[i]) == 0) {
            return (1);
        }
    }
    return (0);
}

int exec_pipes(tree_t *tree, all_t *all_thing, int *pipes_fd, int prev_fd)
{
    int pid = 0;
    int r = if_redirection(tree);
    int status = 0;
    int and = 0;

    if (tree == NULL || error_redirect(tree) == 84)
        return (0);
    pid = fork();
    if (pid == -1)
        return (output_int("Error fork\n"));
    if (pid == 0) {
        norm_exec(tree, pipes_fd, prev_fd, r);
        and = exec_all(tree, all_thing);
    }
    and = is_problem(tree, all_thing);
    exec_pipes_norm(&tree, &pipes_fd, prev_fd, r);
    if (check_if_continue(tree) == true) {
        if (after_exec_gestion(tree, pid, status, and) == 0)
            return (0);
        exec_pipes(tree->right, all_thing, &pipes_fd[2], pipes_fd[0]);
        waitpid(pid, &status, 0);
        and = status_gestion(status);
    }
    return (0);
}

int do_pipes(tree_t *tree, char ***env, hist_t *history)
{
    all_t all_thing;
    int pipes_nbr = get_number_of_pipes(tree);
    int pipes_fd[pipes_nbr * 2];

    all_thing.envi = dup_env(*env);
    all_thing.history = history;
    create_pipes(pipes_fd, pipes_nbr);
    if (exec_pipes(tree, &all_thing, pipes_fd, 0) == 84)
        return (84);
    *env = dup_env(all_thing.envi);
    return (0);
}
