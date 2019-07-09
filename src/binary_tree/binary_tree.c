/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** binary_tree
*/

#include "mysh.h"

tree_t *get_command_node_to_fill(tree_t *tree)
{
    while (tree->right)
        tree = tree->right;
    return (tree);
}

tree_t *get_token_node_to_fill(tree_t *tree)
{
    while (tree) {
        if (tree->left == NULL)
            return (tree);
        tree = tree->right;
    }
    return (tree);
}

int add_command_to_tree(tree_t *tree, char *command, char **env, tree_t *left)
{
    tree_t *node_to_fill = get_command_node_to_fill(tree);

    if (tree->full_command == NULL) {
        tree->is_token = 0;
        tree->full_command = my_str_to_word_array(command, ' ');
        tree->command = tree->full_command[0];
        tree->full_command[0] = search_command(tree->full_command, env, left);
    } else {
        node_to_fill->right = create_command_tree(command, env,
                                                    node_to_fill->left);
        if (node_to_fill->right == NULL) {
            printf("error\n");
            return (84);
        }
    }
    return (SUCCESS);
}

int add_token_to_tree(tree_t *tree, char *token, int i)
{
    tree_t *node_to_fill = get_token_node_to_fill(tree);
    int j = 0;

    node_to_fill->left = create_token_tree(token, i);
    if (node_to_fill->left == NULL)
        return (ERROR);
    while (token[i] == '|' || token[i] == '<'
            || token[i] == '>' || token[i] == '&' || token[i] == ';') {
        i ++;
        j ++;
    }
    return (j - 1);
}
