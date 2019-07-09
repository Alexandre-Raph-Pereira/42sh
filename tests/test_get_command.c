/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_get_command
*/

#include <criterion/criterion.h>
#include "minishell2.h"

Test(get_command, simple_command)
{
    char *str = "ls";
    char *result = get_command(str);

    cr_assert_str_eq(result, "ls");
}

Test(get_command, command_with_token)
{
    char *str = "ls ; clear\n";
    char *result = get_command(str);

    cr_assert_str_eq(result, "ls ");
}

Test(get_command, command_with_spaces)
{
    char *str = "   ls   ; clear";
    char *result = get_command(str);

    cr_assert_str_eq(result, "ls   ");
}

Test(get_command, command_without_spaces)
{
    char *str = "ls;clear";
    char *result = get_command(str);

    cr_assert_str_eq(result, "ls");
}
