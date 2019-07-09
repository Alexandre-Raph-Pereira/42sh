/*
** EPITECH PROJECT, 2019
** env_function.c
** File description:
** env_function.c
*/

#include "mysh.h"

char **printf_env(char *env[])
{
    for (int i = 0; env[i]; i++)
        my_printf("%s\n", env[i]);
    return (env);
}

int env_length(char **arr)
{
    int t = 0;

    for (t = 0; arr[t]; t++);
    return (t);
}

char **add_env(char *new_env[], char **str, int i)
{
    new_env[i] = malloc(sizeof(char) * my_strlen(str[1]) + 3);
    if (new_env[i] == NULL)
        exit(ERROR);
    my_cpy(new_env[i], str[1]);
    new_env[i] = my_strcat(new_env[i], "=");
    return (new_env);
}

int taille_env(char *str)
{
    int i = 0;

    while (str[i] != '=')
        i++;
    return (i);
}

char **cpy_env(char **old_env)
{
    static char **new_env = NULL;
    int j = 0;
    int i = 0;

    while (old_env[i] != NULL)
        i++;
    new_env = malloc(sizeof(char *) * (i + 2));
    if (new_env == NULL)
        return (NULL);
    while (old_env[j]) {
        new_env[j] = malloc(sizeof(char) * (my_strlen(old_env[j]) + 1));
        if (new_env == NULL)
            return (NULL);
        my_cpy(new_env[j], old_env[j]);
        j++;
    }
    new_env[j] = NULL;
    return (new_env);
}
