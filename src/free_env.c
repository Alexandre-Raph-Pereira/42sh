/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** free_env
*/

#include <stdlib.h>

void free_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        free(env[i]);
        i ++;
    }
    free(env);
}
