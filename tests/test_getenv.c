/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** test_getenv
*/
#include <criterion/criterion.h>
#include "minishell2.h"

Test(getenv, returned_value_is_equal)
{
    char *env[] = {"PATH=/usr/bin/", "TEST=", NULL};

    cr_assert_str_eq(my_getenv(env, "PATH"), "/usr/bin/");
}
