/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** create_tree
*/

#include <stdlib.h>
#include "minishell_struct.h"
#include "minishell2.h"
#include "my_printf.h"
#include "my.h"

tree_t *create_command_tree(char *command, char **env, tree_t *left)
{
    tree_t *new_tree = malloc(sizeof(tree_t));

    if (new_tree == NULL)
        return (NULL);
    new_tree->is_token = 0;
    new_tree->full_command = my_str_to_word_array(command, ' ');
    new_tree->command = new_tree->full_command[0];
    new_tree->full_command[0] = search_command(new_tree->full_command, env,
                                                left);
    new_tree->left = NULL;
    new_tree->right = NULL;
    return (new_tree);
}

tree_t *create_token_tree(char *token, int i)
{
    tree_t *new_tree = malloc(sizeof(tree_t));
    int j = 0;

    if (new_tree == NULL)
        return (NULL);
    new_tree->command = NULL;
    new_tree->full_command = NULL;
    new_tree->is_token = 1;
    while (token[i] == '|' || token[i] == '<'
            || token[i] == '>' || token[i] == '&') {
        new_tree->token[j] = token[i];
        i ++;
        j ++;
    }
    new_tree->token[j] = '\0';
    new_tree->left = NULL;
    new_tree->right = NULL;
    return (new_tree);
}
