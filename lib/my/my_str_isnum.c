/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** my_str_isnum
*/

#include <stddef.h>

int my_str_isnum(char const *str)
{
    int x = 0;

    if (!str)
        return (-1);
    if (str[0] < '0' || str[0] > '9') {
        if (!(str[0] == '-' && str[1] != '\0'))
            return (-1);
    } for (int i = 1; str[i] != '\0'; i ++) {
        x = -1;
        if (str[i] < '0' || str[i] > '9')
            return (x);
        x = 0;
    }
    return (x);
}
