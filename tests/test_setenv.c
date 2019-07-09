/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** test_setenv
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell2.h"

Test(setenv, is_equal)
{
    char *envi[] = {"BONJOUR=salut", "PATH=test", NULL};
    char **cop_env = dup_env(envi);
    char *expected_env[] = {"BONJOUR=salut", "PATH=test", "test=salut", NULL};
    char *args[] = {"setenv", "test", "salut", NULL};
    int i = 0;

    exec_setenv(&cop_env, args);
    while (cop_env[i] != NULL) {
        cr_assert_str_eq(cop_env[i], expected_env[i]);
        i++;
    }
    free_env(cop_env);
}

Test(setenv, too_many_arguments, .init = cr_redirect_stdout)
{
    char *envi[] = {"BONJOUR=salut", "PATH=test", NULL};
    char **cop_env = dup_env(envi);
    char *args[] = {"setenv", "bonjour", "salut", "test", NULL};

    exec_setenv(&cop_env, args);
    cr_assert_stdout_eq_str("setenv: Too many arguments.\n");
    free_env(cop_env);
}

Test(setenv, replace_env_variable)
{
    char *envi[] = {"BONJOUR=salut", "PATH=test", "test=salut",NULL};
    char **cop_env = dup_env(envi);
    char *expected_env[] = {"BONJOUR=salut", "PATH=test", "test=salut", NULL};
    char *args[] = {"setenv", "test", "salut", NULL};
    int i = 0;

    exec_setenv(&cop_env, args);
    while (cop_env[i] != NULL) {
        cr_assert_str_eq(cop_env[i], expected_env[i]);
        i++;
    }
    free_env(cop_env);
}

Test(setenv, no_arguments, .init = cr_redirect_stdout)
{
    char *envi[] = {"BONJOUR=salut", "PATH=test", "bonjour=", NULL};
    char **cop_env = dup_env(envi);
    char *args[] = {"setenv", NULL};

    exec_setenv(&cop_env, args);
    cr_assert_stdout_eq_str("BONJOUR=salut\nPATH=test\nbonjour=\n");
    free_env(cop_env);
}
