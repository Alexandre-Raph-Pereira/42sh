/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** free_tree
*/

#include <stdlib.h>
#include "minishell_struct.h"
#include "minishell2.h"

void free_node(tree_t *node)
{
    if (node->is_token == 0)
        if (node->full_command[0] != NULL) {
            free_array(node->full_command);
        }
    free(node);
}

void free_tree(tree_t *tree)
{
    tree_t *save = NULL;

    while (tree) {
        save = tree;
        tree = tree->right;
        if (save->left != NULL)
            free_node(save->left);
        free_node(save);
    }
}
