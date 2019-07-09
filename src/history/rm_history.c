/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** removing some commands from history
*/

#include "mysh.h"

void rm_history_check(char *str, hist_t **list, hist_t **new)
{
    int y = 0;

    for (y = 0; *list != NULL; y ++) {
        if (my_strcmp(beautifull_str(str), (*list)->str) == 0);
        else
            *new = new_comm(str, *new);
        *list = (*list)->next;
    }
}

hist_t *rm_history(hist_t *history, char *str)
{
    hist_t *list = history;
    hist_t *new = malloc(sizeof(hist_t));

    str = my_revstr(str);
    str = my_revstr(str);
    if (my_strcmp(beautifull_str(str), "!") == 0) {
        printf("!: Command not found.\n");
        return (history);
    }
    if (list == NULL || list->str == NULL)
        return (history);
    printf("rm \'%s\'\n", str);
    rm_history_check(str, &list, &new);
    print_hist(new);
    return (new);
}
