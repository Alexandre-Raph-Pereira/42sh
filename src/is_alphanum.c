/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** is_alphanum
*/

#include "mysh.h"
#include "minishell2.h"

int is_alphanum(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    if (c == '_')
        return (FAIL);
    return (SUCCESS);
}

int check_str_is_alphanum(char *str)
{
    if (str[0] != '\0' && !((str[0] >= 'A' && str[0] <= 'Z')
        || (str[0] >= 'a' && str[0] <= 'z'))) {
        my_putstr2("setenv: Variable name must begin with a letter.\n");
        return (SUCCESS);
    }
    for (int i = 0; str[i] != '\0'; i ++)
        if (!is_alphanum(str[i])) {
            my_putstr2("setenv: Variable name must contain alphanumeric ");
            my_putstr2("characters.\n");
            return (SUCCESS);
        }
    return (FAIL);
}
