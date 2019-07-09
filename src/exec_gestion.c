/*
** EPITECH PROJECT, 2019
** exec_gestion.c
** File description:
** exec_gestion
*/

#include "mysh.h"

int after_exec_gestion(tree_t *tree, int pid, int status, int copy_and)
{
    int and = copy_and;

    if (my_strstr(tree->command, "cat") != 1)
        waitpid(pid, &status, 0);
    if (and == 0)
        and = status_gestion(status);
    if (and == 1 && tree->left && tree->left->token[0] == '&')
        return (0);
    if (and == 0 && tree->left && tree->left->token[0] == '|'
        && tree->left->token[1] == '|')
        return (0);
    return (1);
}

int status_gestion(int status)
{
    if (WIFSIGNALED(status)) {
        if (my_strcmp(strsignal(WTERMSIG(status)),
                    "Floating point exception") == 0)
            my_printf("Floating exception\n");
        else
            my_printf("%s\n", strsignal(WTERMSIG(status)));
        return (FAIL);
    } if (WCOREDUMP(status)) {
        my_printf("%s\n", strsignal(WTERMSIG(status)));
        return (FAIL);
    }
    return (SUCCESS);
}

int check_bin(char *str, char *str2)
{
    struct stat sb;

    if (stat(str, &sb) == -1) {
        my_printf("%s: Command not found.\n", str2);
        return (0);
    } 
    else if ((sb.st_mode & S_IXUSR) == 0 || S_ISDIR(sb.st_mode) != 0) {
        my_printf("%s: Permission denied.\n", str2);
        return (0);
    }
    return (FAIL);
}

int exec_redirect(tree_t *tree, int *pipes_fd, int prev_fd)
{
    if (sup_gestion(tree, pipes_fd, prev_fd) == 1)
        return (0);
    if (inf_gestion(tree, pipes_fd, prev_fd) == 1) {
        if (tree->right && tree->right->left &&
            tree->right->left->token[0] == '|'
            && tree->right->left->token[1] != '|') {
            dup2(pipes_fd[1], 1);
        }
        return (0);
    }
    if (tree->right && tree->left && tree->left->token[0] == '|'
        && tree->left->token[1] != '|')
        dup2(pipes_fd[1], 1);
    dup2(prev_fd, 0);
    return (SUCCESS);
}

int my_exec(tree_t *tree, char *new_env[])
{
    if (is_a_builtin(tree->full_command[0]) == 1)
        return (exec_builtin(tree->full_command, &new_env, NULL));
    if (check_bin(tree->full_command[0], tree->full_command[0]) == 0) {
        exit (1);
        return (1);
    }
    if (execve(tree->full_command[0], tree->full_command, new_env) == - 1)
        my_printf("%s: Exec format error. Wrong Architecture.\n",
                tree->full_command[0]);
    return (1);
}
