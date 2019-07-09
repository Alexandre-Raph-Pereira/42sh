/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_setenv
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell2.h"

int exec_setenv(char ***env, char **args)
{
    int nb_args = 0;

    while (args[nb_args] != NULL)
        nb_args ++;
    if (nb_args > 3) {
        write(1, "setenv: Too many arguments.\n", 28);
        return (END);
    } else if (nb_args == 1) {
        exec_env(*env);
        return (SUCCESS);
    }
    return (my_setenv(env, args[1], args[2]));
}

int exec_unsetenv(char ***env, char **args)
{
    int nb_args = 0;

    while (args[nb_args] != NULL)
        nb_args++;
    if (nb_args == 1) {
        write(1, "unsetenv: Too few arguments.\n", 29);
        return (END);
    }
    return (my_unsetenv(env, args));
}
