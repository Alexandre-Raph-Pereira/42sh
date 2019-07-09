/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cd
*/

#include "mysh.h"

int cd_old(char **new_env[], char **arr)
{
    arr = modif_arr(arr, *new_env);
    if (arr == NULL)
        return (FAIL);
    if (check_filepath(arr) == 1)
        *new_env = find_filepath(arr, *new_env);
    return (SUCCESS);
}
