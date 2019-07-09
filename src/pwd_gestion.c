/*
** EPITECH PROJECT, 2019
** pwd_gestion.c
** File description:
** pwd_gestion
*/

#include "mysh.h"

char *my_get_environment(char *new_env[], char *str)
{
    char *str2 = NULL;
    int t = 0;
    int i = 0;
    int j = 0;

    while (new_env[t] != NULL && my_cmp(new_env[t], str) != 0)
        t ++;
    if (new_env[t] == NULL)
        return (NULL);
    str2 = malloc(sizeof(char) * (my_strlen(new_env[t]) + 1));
    while (new_env[t][j] != '=')
        j ++;
    j ++;
    while (new_env[t][j] != '\0') {
        str2[i] = new_env[t][j];
        i ++;
        j ++;
    }
    str2[i] = '\0';
    return (str2);
}

char **modif_arr(char **arr, char *new_env[])
{
    char *str = my_get_environment(new_env, "OLDPWD=");

    if (str == NULL) {
        arr[1] = malloc(sizeof(char) * (1));
        arr[1][0] = '\0';
    }
    else {
        arr[1] = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (arr[1] == NULL)
            return (NULL);
        my_cpy(arr[1], str);
    }
    return (arr);
}

char *find_pwd(void)
{
    char *str = malloc(sizeof(char) * 4096);
    char *path = NULL;
    size_t n = 4096;

    path = getcwd(str, n);
    return (path);
}

char **find_old_pwd(char *str, char *new_env[])
{
    int t = 0;

    while (new_env[t] && my_cmp(new_env[t], "OLDPWD=") != 0)
        t ++;
    if (new_env[t] == NULL)
        new_env = dup_env(new_env);
    else
        free(new_env[t]);
    new_env[t] = malloc(sizeof(char) * (my_strlen(str) + 8));
    my_cpy(new_env[t], "OLDPWD=");
    new_env[t] = my_strcat(new_env[t], str);
    return (new_env);
}
