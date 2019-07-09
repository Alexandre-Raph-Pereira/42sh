/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** retreive_command
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "mysh.h"
#include "my_printf.h"

static int check_token(char letter[3], char **tokens)
{
    for (int i = 0; tokens[i]; i ++)
        if (my_strcmp(letter, tokens[i]) == 0)
            return (FAIL);
    return (SUCCESS);
}

int is_token(char *line, int i)
{
    char *tokens[5] = {"|", ";", ">", "<", NULL};
    char *tokens_double[5] = {">>", "<<", "&&", "||", NULL};
    char letter[3] = {0};

    if (line[i + 1] != '<' && line[i + 1] != '>' && line[i + 1] != '|' &&
        line[i + 1] != '&') {
        letter[0] = line[i];
        letter[1] = '\0';
        return (check_token(letter, tokens));
    } if (line[i + 1] == '<' || line[i + 1] == '>' || line[i + 1] == '|' ||
        line[i + 1] == '&') {
        letter[0] = line[i];
        letter[1] = line[i + 1];
        letter[2] = '\0';
        return (check_token(letter, tokens_double));
    }
    return (SUCCESS);
}

int get_command_size(char *line)
{
    int i = 0;

    while (line[i] != '\0' && !is_token(line, i))
        i ++;
    return (i);
}

char *get_command(char *line)
{
    int i = 0;
    int j = 0;
    char *command = malloc(sizeof(char) * (get_command_size(line) + 1));

    if (command == NULL)
        return (NULL);
    while (line[i] == ' ' || line[i] == '\t')
        i ++;
    while (line[i] != '\0' && !is_token(line, i)) {
        command[j] = line[i];
        i ++;
        j ++;
    }
    command[j] = '\0';
    return (command);
}
