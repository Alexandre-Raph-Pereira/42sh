/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** test_unsetenv
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "minishell2.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unsetenv, is_equal)
{
    char *envi[] = {"BONJOUR=salut", "PATH=test", "bonjour=salut",NULL};
    char **cop_env = dup_env(envi);
    char *expected_env[] = {"BONJOUR=salut", "PATH=test", NULL};
    char *args[] = {"unsetenv", "bonjour", NULL};
    int i = 0;

    my_unsetenv(&cop_env, args);
    while (cop_env[i] != NULL) {
        cr_assert_str_eq(cop_env[i], expected_env[i]);
        i++;
    }
    free_env(cop_env);
}

Test(unsetenv, too_few_arguments, .init = cr_redirect_stdout)
{
    char *envi[] = {"BONJOUR=salut", "PATH=test", "bonjour=salut",NULL};
    char **cop_env = dup_env(envi);
    char *args[] = {"unsetenv", NULL};

    exec_unsetenv(&cop_env, args);
    cr_assert_stdout_eq_str("unsetenv: Too few arguments.\n");
    free_env(cop_env);
}
