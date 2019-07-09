/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** test_env
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell2.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_env, display_env, .init = cr_redirect_stdout)
{
    char *env[3] = {"PATH=/usr/bin/", "TEST=retest", NULL};

    exec_env(env);
    cr_assert_stdout_eq_str("PATH=/usr/bin/\nTEST=retest\n");
}
