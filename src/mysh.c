/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** 42sh
*/

#include "mysh.h"

int my_shell(char **env)
{
    char *user_input = NULL;
    size_t size = 0;
    char **my_env = dup_env(env);
    int is_eof = 0;
    hist_t *history = NULL;

    start_prompt_shell(&is_eof, &user_input, &size);
    while (is_eof != -1) {
        history = new_comm(user_input, history);
        my_env = separator(user_input, my_env, history);
        if (isatty(0) == 1) {
            new_com();
        }
        is_eof = getline(&user_input, &size, stdin);
    }
    free(user_input);
    free_env(my_env);
    if (isatty(0) == 1)
        my_printf("exit\n");
    return (SUCCESS);
}
