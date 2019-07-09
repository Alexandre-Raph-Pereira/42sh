/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** setenv
*/

#include "mysh.h"

int count_lines(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}

char *create_new_line(char *var, char *val)
{
    char *new_line = NULL;
    char *save = NULL;

    if (val == NULL) {
        new_line = my_strmcat(var, "=");
        if (new_line == NULL)
            return (NULL);
    } else {
        new_line = my_strmcat(var, "=");
        if (new_line == NULL)
            return (NULL);
        save = new_line;
        new_line = my_strmcat(new_line, val);
        free(save);
        if (new_line == NULL)
            return (NULL);
    }
    return (new_line);
}

int copy_env(char **new_env, char **env, char *var, char *val)
{
    int i = 0;

    if (var == NULL && val == NULL) {
        exec_env(env);
        return (END);
    }
    while (env[i] != NULL) {
        new_env[i] = my_strcpy(env[i]);
        if (new_env == NULL)
            return (ERROR);
        i++;
    }
    new_env[i] = NULL;
    new_env[i + 1] = NULL;
    return (SUCCESS);
}

int get_var(char **env, char *var)
{
    for (int i = 0; env[i] != NULL; i++)
        if (compare_vars(env[i], var) == 1)
            return (i);
    return (SUCCESS);
}

int my_setenv(char ***env, char *var, char *val)
{
    int nb_lines = count_lines(*env);
    char **new_env = malloc(sizeof(char *) * (nb_lines + 2));
    int pos = 0;

    if (!check_str_is_alphanum(var))
        return (END);
    if (new_env == NULL)
        return (FAIL);
    pos = get_var(*env, var);
    copy_env(new_env, *env, var, val);
    if (pos != 0)
        new_env[pos] = create_new_line(var, val);
    else
        new_env[count_lines(*env)] = create_new_line(var, val);
    free_env(*env);
    *env = new_env;
    return (SUCCESS);
}
