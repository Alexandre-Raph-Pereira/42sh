/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** get_number_of_pipes
*/

#include "minishell2.h"
#include "minishell_struct.h"

int get_number_of_pipes(tree_t *tree)
{
    int i = 0;

    while (tree) {
        if (get_token_in_tree(tree) != '|' && get_token_in_tree(tree) != '<'
            && get_token_in_tree(tree) != '>'
            && get_token_in_tree(tree) != '&')
            return (i);
        i++;
        tree = tree->right;
    }
    return (i);
}