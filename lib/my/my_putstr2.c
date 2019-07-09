/*
** EPITECH PROJECT, 2019
** my_putstr2.c
** File description:
** my_putstr2
*/

#include <unistd.h>

void my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}
