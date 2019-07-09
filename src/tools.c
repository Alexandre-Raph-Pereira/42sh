/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Error file tools
*/

#include "minishell2.h"

void display_error(char *msg, char *var)
{
    if (var) {
        my_putstr2(var);
        free(var);
    } if (msg)
        my_putstr2(msg);
}

int output_int(char *str)
{
    if (str != NULL) {
        printf("%s", str);
        free(str);
    }
    return (ERROR);
}
