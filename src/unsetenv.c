/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** unsetenv
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

int is_line_to_remove(char *env_line, char **args)
{
    for (int i = 1; args[i] != NULL; i ++)
        if (compare_vars(args[i], env_line) == FAIL)
            return (FAIL);
    return (SUCCESS);
}

int check_var_args(char **env, char **args)
{
    int lines_to_remove = 0;

    for (int i = 0; env[i] != NULL; i ++)
        lines_to_remove += is_line_to_remove(env[i], args);
    return (lines_to_remove);
}

int check_if_remove(char *env_line, char **args)
{
    for (int i = 1; args[i] != NULL; i ++)
        if (compare_vars(env_line, args[i]) == 1)
            return (FAIL);
    return (SUCCESS);
}

int add_line(char *env, char **new_env, char **args, int i)
{
    if (check_if_remove(env, args) == 0) {
        new_env[i] = my_strcpy(env);
        if (new_env == NULL)
            return (ERROR);
        return (FAIL);
    }
    return (SUCCESS);
}

int my_unsetenv(char ***env, char **args)
{
    int nb_correct_lines = check_var_args(*env, args);
    int nb_lines = count_lines(*env);
    int i = 0;
    int j = 0;
    char **new_env = malloc(sizeof(char *) *
                            (nb_lines - nb_correct_lines + 1));

    if (new_env == NULL)
        return (END);
    while ((*env)[i] != NULL) {
        if (add_line((*env)[i], new_env, args, j) == 1)
            j++;
        i++;
    }
    new_env[j] = NULL;
    free_env(*env);
    *env = new_env;
    return (SUCCESS);
}
