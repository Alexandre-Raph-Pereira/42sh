/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_next_redirection
*/

#include "mysh.h"

int check_next_redirect(tree_t *tree, int *pipes_next,
        int *pipes_fd, int prev_fd)
{
    tree_t *copy = tree->right;

    while (copy != NULL) {
        if (copy->left && copy->left->token[0] == '&')
            return (0);
        if (sup_gestion(copy, pipes_fd, prev_fd) == 1)
            return (1);
        inf_gestion(copy, pipes_fd, prev_fd);
        if (copy->right && copy->left && copy->left->token[0] == '|'
            && copy->left->token[1] != '|') {
            dup2(prev_fd, pipes_fd[1]);
            return (0);
        }
        copy = copy->right;
    }
    return (0);
}
