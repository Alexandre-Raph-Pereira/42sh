/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** jump_wrong_commands
*/

#include <stdlib.h>
#include "minishell_struct.h"
#include "my_printf.h"
#include "mysh.h"

void move_while_pipe(tree_t **tree)
{
    while ((*tree)->left && is_redirect_or_pipe((*tree)->left->token))
        *tree = (*tree)->right;
}

int check_wrong_commands(tree_t *tree)
{
    while (tree) {
        if (tree->full_command[0] == NULL)
            return (1);
        tree = tree->right;
    }
    return (0);
}

int jump_wrong_commands(tree_t **tree)
{
    tree_t *cursor = *tree;

    do {
        if (cursor->full_command[0] == NULL) {
            move_while_pipe(tree);
            return (1);
        }
        cursor = cursor->right;
    } while (cursor != NULL && cursor->left && cursor->left->token[0] != '|');
    return (0);
}
