/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Separator file
*/

#include "mysh.h"

char **separator(char *commands, char **env, hist_t *history)
{
    char *sp[7] = {"|", ";", "<<", ">>", "&&", "||", NULL};
    char **av = my_str_to_array(commands);
    char **test = my_str_to_word_array(commands, ' ');

    for (int j = 0; test[j] != NULL; j++) {
        if ((test[j][0] == '|' || test[j][0] == '>' ||
            test[j][0] == '<' || test[j][0] == '&' || test[j][0] == ';') &&
            test[j + 1] == NULL) {
                my_printf("invalid command\n");
                return (env);
        }
    }
    for (int i = 0; sp[i] != NULL; i ++)
        if (my_strcmp(beautifull_str(commands), sp[i]) == 0)
            return (env);
    for (int i = 0; av[i] != NULL; i ++) {
        env = select_command(av[i], env, history);
    }
    return (env);
}
