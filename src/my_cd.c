/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_cd
*/

#include "mysh.h"

char **my_cd(char **env, char **args)
{
    char *dir = NULL;

    if (args[1] == NULL) {
        dir = my_getenv(env, "HOME");
        chdir(dir);
        free(dir);
    } else if (chdir(args[1]) == -1) {
        if (access(args[1], F_OK) == -1)
            display_error(": No such file or directory.\n", args[1]);
        else if (access(args[1], X_OK) == -1)
            display_error(": Permission denied.\n", args[1]);
        else
            display_error(": Not a directory.\n", args[1]);
    }
    return (env);
}
