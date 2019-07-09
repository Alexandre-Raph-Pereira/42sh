/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** error_gestion
*/

#include "mysh.h"

int is_problem(tree_t *tree, all_t *all_thing)
{
    if (is_modifing_env(tree->command) == 1)
        return (exec_builtin(tree->full_command,
                &all_thing->envi, all_thing->history));
    if (check_exec(tree->full_command[0], tree->full_command[0]) == 0)
        return (1);
    return (0);
}

int check_exec(char *str, char *str2)
{
    struct stat sb;

    if (stat(str, &sb) == -1) {
        return (0);
    } 
    else if ((sb.st_mode & S_IXUSR) == 0 || S_ISDIR(sb.st_mode) != 0) {
        return (0);
    }
    return (1);
}

int error_sup(char *arr)
{
    struct stat sb;

    if (stat(arr, &sb) == -1)
        return (1);
    else if ((sb.st_mode & S_IWUSR) == 0) {
        my_putstr2(arr);
        my_putstr2(": Permission denied.\n");
        return (84);
    }
    return (1);
}

int error_inf(char *arr)
{
    struct stat sb;

    if (stat(arr, &sb) == -1) {
        my_putstr2(arr);
        my_putstr2(": No such file or directory\n");
        return (84);
    }
    else if ((sb.st_mode & S_IRUSR) == 0) {
        my_putstr2(arr);
        my_putstr2(": Permission denied.\n");
        return (84);
    }
    return (1);
}

int error_redirect(tree_t *tree)
{
    tree_t *copy = tree;
    int r = 0;

    if (copy->left != NULL && copy->left->token[0] == '>') {
        r = error_sup(copy->right->command);
    }
    if (copy->left != NULL && copy->left->token[0] == '<'
        && copy->left->token[1] != '<') {
        r = error_inf(copy->right->command);
    }
    if (r == 84)
        return (84);
    return (r);
}