/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Unit tests on lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(lib_strlen2, simple_string, .init = redirect_all_std)
{
    char *str = "salut";
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, 5);
}

Test(lib_strlen3, simple_string, .init = redirect_all_std)
{
    char *str = "salut\0 ca va ?";
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, 5);
}

Test(lib_getnbr1, simple_string, .init = redirect_all_std)
{
    char *str = "42";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 42);
}

Test(lib_getnbr2, simple_string, .init = redirect_all_std)
{
    char *str = "42salutlama";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 42);
}

Test(lib_getnbr3, simple_string, .init = redirect_all_std)
{
    char *str = "salutlama42";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 0);
}

Test(lib_strstr1, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lama";
    int result = 0;

    result = my_strstr(str, str2);
    cr_expect_eq(result, 1);
}

Test(lib_strstr2, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_strstr(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_strstr3, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_strstr(str2, str);
    cr_expect_eq(result, 1);
}

Test(lib_str_isnum1, simple_string, .init = redirect_all_std)
{
    char *str = "#";
    int result = my_str_isnum(str);

    cr_expect_eq(result, -1);
}

Test(lib_str_isnum2, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = my_str_isnum(str);

    cr_expect_eq(result, -1);
}

Test(lib_str_isnum3, simple_string, .init = redirect_all_std)
{
    char *str = "0123456789";
    int result = my_str_isnum(str);

    cr_expect_eq(result, 0);
}

Test(lib_str_isnum4, simple_string, .init = redirect_all_std)
{
    char *str = "j'ai 4 ans";
    int result = my_str_isnum(str);

    cr_expect_eq(result, -1);
}

Test(lib_my_printf1, simple_string, .init = redirect_all_std)
{
    my_printf("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(lib_my_printf2, simple_string2, .init = redirect_all_std)
{
    my_printf("abcdefghijklmnopqrstuvwxyz0123456789()+-*/%\n");
    cr_assert_stdout_eq_str("abcdefghijklmnopqrstuvwxyz0123456789()+-*/%");
}

Test(lib_my_printf3, simple_string3, .init = redirect_all_std)
{
    my_printf("je fais une phrase, pour tester un cas courant\n");
    cr_assert_stdout_eq_str("je fais une phrase, pour tester un cas courant\n");
}

Test(lib_my_printf4, simple_string_modulo, .init = redirect_all_std)
{
    my_printf("modulo %%\n");
    cr_assert_stdout_eq_str("modulo %\n");
}

Test(lib_my_printf5, simple_string_modulo2, .init = redirect_all_std)
{
    my_printf("le symbole %% est un simple modulo\n");
    cr_assert_stdout_eq_str("le symbole % est un simple modulo\n");
}

Test(lib_my_printf9, simple_string_binary3, .init = redirect_all_std)
{
    int ui = 93773055;

    my_printf("binary = %b\n", ui);
    cr_assert_stdout_eq_str("binary = 101100101101101110011111111\n");
}

Test(lib_my_printf10, simple_string_char, .init = redirect_all_std)
{
    char c = 'c';

    my_printf("char = %c\n", c);
    cr_assert_stdout_eq_str("char = c\n");
}

Test(lib_my_printf11, simple_string_char2, .init = redirect_all_std)
{
    char c = 'q';

    my_printf("char = %c\n", c);
    cr_assert_stdout_eq_str("char = q\n");
}

Test(lib_my_printf12, simple_string_char3, .init = redirect_all_std)
{
    char c = 'r';

    my_printf("char = %c\n", c);
    cr_assert_stdout_eq_str("char = r\n");
}

Test(lib_my_printf13, simple_string_intd, .init = redirect_all_std)
{
    int i = 42;

    my_printf("int = %d\n", i);
    cr_assert_stdout_eq_str("int = 42\n");
}

Test(lib_my_printf14, simple_string_intd2, .init = redirect_all_std)
{
    int i = 84000;

    my_printf("int = %d\n", i);
    cr_assert_stdout_eq_str("int = 84000\n");
}

Test(lib_my_printf15, simple_string_intd3, .init = redirect_all_std)
{
    int i = 100000;

    my_printf("int = %d\n", i);
    cr_assert_stdout_eq_str("int = 100000\n");
}

Test(lib_my_printf19, simple_string_inti, .init = redirect_all_std)
{
    int i = 42;

    my_printf("int = %i\n", i);
    cr_assert_stdout_eq_str("int = 42\n");
}

Test(lib_my_printf20, simple_string_inti2, .init = redirect_all_std)
{
    int i = 84000;

    my_printf("int = %i\n", i);
    cr_assert_stdout_eq_str("int = 84000\n");
}

Test(lib_my_printf21, simple_string_inti3, .init = redirect_all_std)
{
    int i = 1000000;

    my_printf("int = %i\n", i);
    cr_assert_stdout_eq_str("int = 1000000\n");
}

