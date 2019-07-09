/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** History file
*/

#include "mysh.h"

static void nbr_print(int i)
{
    int status = 0;

    if (i < 10) {
        printf("     %d", i);
        status = 1;
    } if (status == 0 && i < 100) {
        printf("    %d", i);
        status = 1;
    } if (status == 0 && i < 1000) {
        printf("   %d", i);
        status = 1;
    } if (status == 0 && i < 10000)
        printf("  %d", i);
}

int print_hist(hist_t *history)
{
    int w = 0;
    int i = 0;
    hist_t *list = history;

    if (list == NULL || list->str == NULL)
        return (ERROR);
    for (w = 0; list != NULL; w ++)
        list = list->next;
    list = history;
    for (; w != 0; i ++) {
        for (int y = 1; y != w; y ++)
            list = list->next;
        nbr_print(i);
        printf(" %s", list->str);
        list = history;
        w --;
    }
    nbr_print(i);
    printf(" history\n");
    return (SUCCESS);
}

hist_t *new_comm(char *com, hist_t *history)
{
    hist_t *new = malloc(sizeof(hist_t));

    if (my_strcmp(com, "history\n") == 0 || my_strcmp(com, "\n") == 0)
        return (history);
    new->str = my_strcpy(com);
    new->next = history;
    error_log(new);
    return (new);
}
