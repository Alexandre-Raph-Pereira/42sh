/*
** EPITECH PROJECT, 2019
** cd_function.c
** File description:
** cd_function
*/

#include "mysh.h"

int check_filepath(char **arr)
{
    struct stat sb;

    if (stat(arr[1], &sb) == -1) {
        my_putstr2(arr[1]);
        my_putstr2(": No such file or directory.\n");
        return (SUCCESS);
    } if (S_ISDIR(sb.st_mode) == 0) {
        my_putstr2(arr[1]);
        my_putstr2(": Not a directory.\n");
        return (SUCCESS);
    } else if ((sb.st_mode & S_IXUSR) == 0) {
        my_putstr2(arr[1]);
        my_putstr2(": Permission denied.\n");
        return (SUCCESS);
    }
    return (FAIL);
}

char **change_pwd(char *str, char *new_env[])
{
    int t = 0;

    while (new_env[t] != NULL && my_cmp(new_env[t], "PWD=") != 0)
        t++;
    if (new_env[t] != NULL)
        free(new_env[t]);
    else
        new_env = dup_env(new_env);
    if (new_env == NULL)
        return (NULL);
    new_env[t] = malloc(sizeof(char) * (my_strlen(str) + 5));
    my_cpy(new_env[t], "PWD=");
    new_env[t] = my_strcat(new_env[t], str);
    return (new_env);
}

char **find_home(char *new_env[])
{
    int t = 0;
    int j = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        exit(84);
    for (; new_env[t] && my_cmp(new_env[t], "HOME="); t++);
    if (new_env[t] == NULL) {
        my_printf("HOME not set\n");
        return (new_env);
    }
    for (; new_env[t][j] != '/'; j++);
    for (; new_env[t][j] != '\0'; j++) {
        str[i] = new_env[t][j];
        i ++;
    }
    str[i] = '\0';
    chdir(str);
    return (change_pwd(str, new_env));
}

char **find_filepath(char **arr, char *new_env[])
{
    int t = 0;
    char *str = malloc(sizeof(char) * 4094);
    size_t n = 4094;

    if (str == NULL)
        exit(ERROR);
    while (new_env[t] != NULL && my_cmp(new_env[t], "PWD=") != 0)
        t ++;
    if (new_env[t] != NULL)
        free(new_env[t]);
    chdir(arr[1]);
    getcwd(str, n);
    new_env[t] = malloc(sizeof(char) * my_strlen(str) + 5);
    if (new_env[t] == NULL)
        exit(ERROR);
    my_cpy(new_env[t], "PWD=");
    new_env[t] = my_strcat(new_env[t], str);
    free(str);
    return (new_env);
}

int cd_function(char **new_env[], char **arr)
{
    char *str2 = find_pwd();
    int t = env_length(arr);

    if (t == 1)
        *new_env = find_home(*new_env);
    if (t == 2 && my_cmp(arr[1], "-") == SUCCESS && my_strlen(arr[1]) == 1) {
        if (cd_old(new_env, arr) == FAIL)
            return (FAIL);
    } else if (t == 2) {
        if (check_filepath(arr) == 1)
            *new_env = find_filepath(arr, *new_env);
        else {
            free(str2);
            return (END);
        }
    }
    *new_env = find_old_pwd(str2, *new_env);
    free(str2);
    return (SUCCESS);
}
