/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** jump_redirections
*/

#include "minishell2.h"
#include "minishell_struct.h"

int is_redirection(char *c)
{
    if (c[0] == '>' || c[0] == '<')
        return (FAIL);
    return (SUCCESS);
}

int has_redirections(tree_t *tree)
{
    while (tree) {
        if (tree->left && is_redirection(tree->left->token))
            return (FAIL);
        tree = tree->right;
    }
    return (SUCCESS);
}
