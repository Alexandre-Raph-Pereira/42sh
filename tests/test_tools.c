/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Tools Criterion test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(output_1, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = output_int(str);

    cr_expect_eq(result, 84);
}

Test(output_2, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = 0;

    str = my_strcpy("TEST FAILED");
    if (str == NULL)
        result = 84;
    else
        result = output_int(str);
    cr_expect_eq(result, 84);
}

Test(cd, is_equal)
{
    char *env[] = {"PWD=/home/apereira/Music", "HOME=/home/apereira", NULL};
    char **env_copied = dup_env(env);
    char *new_env[] =  {"PWD=/home/apereira", "HOME=/home/apereira", NULL};
    char str[] = "cd";
    char **arg = my_str_to_word_array(str, ' ');
    int i = 0;
    int r = 0;

    r = cd_function(&env_copied, arg);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(cd, is_equal_not_eq, .init = redirect_all_std)
{
    char *env[] = {"PWD=/home/apereira", "HOME=/home/apereira",NULL};
    char **env_copied = dup_env(env);
    char str[] = "cd salut";
    char **arg = my_str_to_word_array(str, ' ');
    int r = 0;

    r = cd_function(&env_copied, arg);
    cr_assert_stderr_eq_str("salut: No such file or directory.\n");
}