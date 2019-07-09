/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_exit
*/

#include "mysh.h"

int my_exit(char ***env, char **args)
{
    int nb_arg = env_length(args);
    int nb = 0;

    if (args == NULL || nb_arg >= 3 ||
        (args[1] != NULL && my_str_isnum(args[1]) == -1)) {
        my_putstr2("exit: Expression Syntax.\n");
        return (END);
    } if (nb_arg == 2)
        nb = my_getnbr(args[1]);
    if (isatty(0) == 1)
        my_putstr("exit\n");
    free_array(args);
    free_env(*env);
    exit(nb);
}
