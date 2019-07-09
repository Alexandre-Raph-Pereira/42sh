/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_command_line
*/

#include "mysh.h"

static int have_command(char *line)
{
    char **str = my_str_to_array(line);

    if (str == NULL || str[0] == NULL || (env_length(str) < 2 &&
        str[0][0] != '\0' && (str[0][0] == ';' || str[0][0] == '|'
        || str[0][0] == '&' || str[0][0] == '<' || str[0][0] == '>'))) {
        if (str != NULL)
            free_array(str);
        return (FAIL);
    }
    free_array(str);
    for (int i = 0; line[i] != '\0'; i ++)
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (SUCCESS);
    return (FAIL);
}

void select_command_check_line(char *line, tree_t **tree,
        int *status, char **env)
{
    if (line == NULL || have_command(line) == FAIL
        || my_str_isprintable(line) == -1) {
        *status = 1;
        return;
    }
    *tree = parse_line(line, env);
    if (!(*tree)) {
        *status = 1;
        return;
    }
}