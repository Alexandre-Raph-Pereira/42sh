/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** get_token_in_tree
*/

#include "minishell_struct.h"

char get_token_in_tree(tree_t *tree)
{
    if (!tree)
        return ('a');
    else if (!tree->left)
        return ('a');
    return (tree->left->token[0]);
}
