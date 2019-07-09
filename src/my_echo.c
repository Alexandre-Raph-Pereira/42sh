/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_echo
*/

#include "mysh.h"

static int quote_or_not(char c)
{
    if (c == '\"')
        return (FAIL);
    return (SUCCESS);
}

static int check_quote(char **args)
{
    int k = 0;

    for (int i = 1; args[i] != NULL; i ++)
        for (int j = 0; args[i][j] != '\0'; j ++)
            k += quote_or_not(args[i][j]);
    if (k % 2 != 0) {
        my_putstr2("Unmatched '\"'.\n");
        return (END);
    }
    return (0);
}

static int check_var(char *arg, char **env, int *i)
{
    int len = echo_var_len(arg, *i + 1);
    char *var = my_strntoncpy(arg, *i + 1, len);

    (*i)++;
    if (var == NULL)
        return (-1);
    if (!check_str_is_alphanum(var)) {
        my_putstr2("Illegal variable name.\n");
        free(var);
        return (END);
    }
    if (my_get_environment(env, var) == NULL) {
        my_putstr2(var);
        my_putstr2(": Undefined variable.\n");
        free(var);
        return (END);
    }
    *i += len - 1;
    free(var);
    return (SUCCESS);
}

static int echo_handling_error(char *arg, char **env)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (arg[i] == '$' && check_var(arg, env, &i) == -1)
            return (END);
    return (SUCCESS);
}

int my_echo(char ***env, char **args)
{
    if (args == NULL && args[0] != NULL) {
        printf("\n");
        return (SUCCESS);
    } if (check_quote(args) == -1)
        return (1);
    for (int i = 1; args[i] != NULL; i++)
        if (echo_handling_error(args[i], *env) == END)
            return (1);
    return (print_echo(args, env));
}
