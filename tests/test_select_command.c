/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** test_select_command
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell2.h"
/*   FIXME
Test(select_command, select_env, .init = cr_redirect_stdout)
{
    char *env[] = {"BONJOUR=salut", "PATH=test", "bonjour=", NULL};
    char **cop_env = dup_env(env);

    select_command("env", cop_env);
    cr_assert_stdout_eq_str("BONJOUR=salut\nPATH=test\nbonjour=\n");
    free_env(cop_env);
}*/
Test(select_command, select_setenv)
{
    char *env[] = {"BONJOUR=salut", "PATH=test", NULL};
    char **cop_env = dup_env(env);
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
