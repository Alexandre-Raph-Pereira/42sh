/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Prints a string
*/

#include <unistd.h>

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]!= '\0')
        i++;
    return (i);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
