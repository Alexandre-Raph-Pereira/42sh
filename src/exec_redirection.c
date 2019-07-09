/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec_redirection
*/

#include "mysh.h"

int sup_gestion(tree_t *tree, int *pipes_fd, int prev_fd)
{
    int fd = 0;

    if (tree->left != NULL && tree->left->token[0] == '>'
        && tree->left->token[1] != '>') {
        fd = open(tree->right->command, O_RDWR | O_CREAT | O_TRUNC, 0644);
        dup2(fd, 1);
        close(fd);
        dup2(prev_fd, 0);
        return (1);
    }
    if (tree->left != NULL && tree->left->token[0] == '>'
        && tree->left->token[1] == '>') {
        fd = open(tree->right->command, O_RDWR | O_CREAT | O_APPEND, 0644);
        dup2(fd, 1);
        close(fd);
        dup2(prev_fd, 0);
        return (1);
    }
    return (0);
}

int double_inf(tree_t *tree, int *pipes_fd, int prev_fd)
{
    char *str = NULL;

    if (tree->left != NULL && tree->left->token[0] == '<'
        && tree->left->token[1] == '<') {
        str = get_next_line(prev_fd);
        while (str != NULL && my_strcmp(str, tree->right->command) != 0) {
            free(str);
            str = get_next_line(prev_fd);
        }
        write(prev_fd, '\0', 1);
        dup2(prev_fd, 0);
        return (1);
    }
    return (0);
}

int inf_gestion(tree_t *tree, int *pipes_fd, int prev_fd)
{
    int fd = 0;

    if (tree->left != NULL && tree->left->token[0] == '<'
        && tree->left->token[1] != '<') {
        fd = open(tree->right->command, O_RDONLY);
        dup2(fd, 0);
        close(fd);
        return (1);
    }
    if (double_inf(tree, pipes_fd, prev_fd) == 1)
        return (1);
    return (0);
}
