/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** parser
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "my.h"
#include "mysh.h"

tree_t *create_first_command_tree(void)
{
    tree_t *new_tree = malloc(sizeof(tree_t));

    if (new_tree == NULL)
        return (NULL);
    new_tree->command = NULL;
    new_tree->full_command = NULL;
    new_tree->is_token = 0;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return (new_tree);
}

int jump_spaces(char *str)
{
    int i = 0;

    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        i ++;
    return (i);
}

int add_command(char *line, char **env, tree_t *tree, tree_t *left)
{
    char *command = NULL;
    int i = 0;

    command = get_command(line);
    i = my_strlen(command) - 1;
    add_command_to_tree(tree, command, env, left);
    free(command);
    return (i);
}

tree_t *parse_line(char *line, char **env)
{
    tree_t *tree = create_first_command_tree();
    tree_t *copy = tree;
    int have_token = 0;

    if (tree == NULL)
        return (NULL);
    for (int i = 0; line != NULL && line[i] != '\0'; i++) {
        i += jump_spaces(&line[i]);
        if (is_token(line, i) && have_token == 0) {
            i += add_token_to_tree(tree, line, i) + 1;
            have_token = 1;
            copy = tree;
        } else if (is_token(line, i) && have_token == 1) {
            my_putstr2("Invalid null command\n");
            return (NULL);
        } else {
            i += add_command(&line[i], env, tree, copy->left);
            have_token = 0;
        }
    }
    return (tree);
}
