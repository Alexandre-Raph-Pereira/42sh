/*
** EPITECH PROJECT, 2018
** my_putint_in_str.c
** File description:
** HEADER
*/

#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str);

char *my_putint_in_str(int z)
{
    int r = z;
    int s = 0;
    int n = 0;
    int b = 10;
    char *str = malloc(sizeof(char) * 12);

    if (z == 0)
        return ("0");
    for (r = z; r != 0; r /= 10, s ++);
    while (s != 0) {
        str[n] = (z % 10 + '0');
        n ++;
        s --;
        z = z / 10;
    }
    str[n] = '\0';
    str = my_revstr(str);
    return (str);
}
