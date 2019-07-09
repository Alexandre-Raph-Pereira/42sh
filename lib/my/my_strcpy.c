/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Copies a string into another
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char const *str)
{
    char *new_str = malloc(my_strlen(str) + 1);
    int i = 0;

    if (new_str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
