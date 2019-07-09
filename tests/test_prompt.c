/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Test Criterion prompt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Prompt_1, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = output_int(str);

    cr_expect_eq(result, 84);
}

Test(Prompt_2, simple_string, .init = redirect_all_std)
{
    char **av = "PWD=/home/romeo/PSU_42sh_2018 USER=romeo";
    int result = 0;

    cr_expect_eq(result, 84);
}

