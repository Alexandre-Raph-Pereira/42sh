/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** start_prompt_shell
*/

#include "mysh.h"

void ctrl_c(int signal)
{
    (void)signal;
    if (isatty(0) == 1) {
        my_printf("\n");
        new_com();
    }
}

void start_prompt_shell(int *is_eof, char **user_input, size_t *size)
{
    if (isatty(0) == 1)
        new_com();
    signal(SIGINT, ctrl_c);
    *is_eof = getline(user_input, size, stdin);
}