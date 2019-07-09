/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pipes_norm
*/

#include "mysh.h"

void exec_pipes_norm(tree_t **tree, int **pipes_fd, int prev_fd, int r)
{
    if (r == 1)
        check_next_redirect(*tree, pipes_fd[2], *pipes_fd, (*pipes_fd)[0]);
    for (; r > 0; r--)
        *tree = (*tree)->right;
    if ((*tree)->right && (*tree)->left && (*tree)->left->token[0] == '|')
        close((*pipes_fd)[1]);
}