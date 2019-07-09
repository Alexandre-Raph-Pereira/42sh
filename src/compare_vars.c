/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** compare_vars
*/

#include "minishell2.h"

int compare_vars(char const *var, char const *arg)
{
    int i = 0;

    if (var == NULL || arg == NULL)
        return (SUCCESS);
    while (var[i] != '=' || arg[i] != '\0') {
        if (var[i] != arg[i])
            return (SUCCESS);
        i ++;
    }
    return (FAIL);
}
