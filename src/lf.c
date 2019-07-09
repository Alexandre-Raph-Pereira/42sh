/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** lf file
*/

#include "minishell2.h"

char *forloc(char *str)
{
    int y = 0;
    int o = 0;
    char *nstr = my_strcpy(my_revstr(str));

    while (nstr[y]) {
        if (nstr[y] == '/')
            o++;
        y++;
    }
    y = 0;
    if (o == 2)
        return (NULL);
    while (nstr[y]) {
        if (nstr[y] == '/') {
            nstr[y] = '\0';
            return (my_revstr(nstr));
        }
        y++;
    }
    return (NULL);
}
