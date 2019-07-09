/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_tokens
*/

#include <stdbool.h>
#include <stdlib.h>
#include <my.h>

int is_redirect_or_pipe(char *c)
{
    const char *tokens[8] = {"|", ">", "<", ">>", "<<", "||", "&&", NULL};

    for (int i = 0; tokens[i] != NULL; i++) {
        if (my_strcmp(c, tokens[i]) == 0)
            return (true);
    }
    return (false);
}