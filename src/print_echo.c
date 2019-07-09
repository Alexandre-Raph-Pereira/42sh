/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** print_echo
*/

#include "mysh.h"

int echo_var_len(char *arg, int i)
{
    int len = 0;

    for (; arg[i] != '\0' && arg[i] != '$' && arg[i] != '\"'; i++)
        len ++;
    return (len);
}

static void echo_print_var(char *arg, char **env, int *i)
{
    int len = echo_var_len(arg, *i);
    char *var = my_strntoncpy(arg, *i, len);

    if (len == 0) {
        my_printf("$");
        *i += len - 1;
    }
    if (var == NULL || len == 0)
        return;
    my_printf("%s", my_get_environment(env, var));
    *i += len - 1;
    free(var);
}

static void echo_print_arg(char *arg, char **env)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == '$') {
            i ++;
            echo_print_var(arg, env, &i);
        } else if (arg[i] != '\"')
            write(1, &arg[i], 1);
    }
    return;
}

int print_echo(char **args, char ***env)
{
    for (int i = 1; args[i] != NULL; i++) {
        echo_print_arg(args[i], *env);
        if (args[i + 1] != NULL)
            my_printf(" ");
    }
    my_printf("\n");
    return (SUCCESS);
}
