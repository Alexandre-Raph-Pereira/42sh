/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_strmcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strmcat(char const *str1, char const *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (size1 + size2 + 1));

    if (str == NULL)
        return (NULL);
    for (; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (; str2[j] != '\0'; j++)
        str[i + j] = str2[j];
    str[i + j] = '\0';
    return (str);
}
