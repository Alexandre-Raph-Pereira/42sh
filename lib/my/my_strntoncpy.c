/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** useful_fonctions_two
*/

#include <stdlib.h>

char *my_strntoncpy(char *str, int start, int size)
{
    char *dest = malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; i < size && str[start] != '\0'; i++) {
        dest[i] = str[start];
        start++;
    }
    dest[i] = '\0';
    return (dest);
}