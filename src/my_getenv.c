/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_getenv
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell2.h"

int get_equal_pos(char *var)
{
    int i = 0;

    while (var[i] != '\0' && var[i] != '=')
        i++;
    return (i);
}

void copy_value(char *value, char const *var, int val_beginning)
{
    int i = 0;

    while (var[val_beginning + i] != '\0') {
        value[i] = var[val_beginning + i];
        i++;
    }
    value[i] = '\0';
}

char *my_getenv(char **env, char *var_name)
{
    int i = 0;
    int j = 0;
    int val_beginning = 0;
    char *value = NULL;

    while (env[i] != NULL && compare_vars(env[i], var_name) != 1)
        i++;
    if (env[i] == NULL)
        return (NULL);
    val_beginning = get_equal_pos(env[i]);
    while (env[i][val_beginning + j] != '\0')
        j++;
    value = malloc(sizeof(char) * (j + 1));
    if (value == NULL)
        return (NULL);
    copy_value(value, env[i], val_beginning + 1);
    return (value);
}
