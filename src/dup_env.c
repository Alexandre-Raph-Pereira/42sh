/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** Duplicates the environnement
*/

#include <stdlib.h>
#include "my.h"
#include "minishell2.h"

char **dup_env(char **env)
{
    int i = 0;
    int nb_lines = count_lines(env);
    char **new_env = malloc(sizeof(char *) * (nb_lines + 2));

    while (env[i] != NULL) {
        new_env[i] = my_strcpy(env[i]);
        if (new_env[i] == NULL)
            return (NULL);
        i ++;
    }
    new_env[i] = NULL;
    new_env[i + 1] = NULL;
    return (new_env);
}
