/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Log file
*/

#include "mysh.h"

static char *nbr_print(int i)
{
    char *str = malloc(sizeof(char) * (my_strlen(my_putint_in_str(i)) + 10));
    int status = 0;

    if (i < 10) {
        str = my_strcat("     ", my_putint_in_str(i));
        status = 1;
    } if (status == 0 && i < 100) {
        str = my_strcat("    ", my_putint_in_str(i));
        status = 1;
    } if (status == 0 && i < 1000) {
        str = my_strcat("   ", my_putint_in_str(i));
        status = 1;
    } if (status == 0 && i < 10000)
        str = my_strcat("  ", my_putint_in_str(i));
    return (str);
}

static void free_line(char *line)
{
    if (line)
        free(line);
}

static void cpy_log(hist_t **list, hist_t **history, int fd)
{
    char *line = NULL;
    int w = 0;
    int y = 0;
    int i = 0;

    for (w = 0; *list != NULL; w ++)
        *list = (*list)->next;
    *list = *history;
    for (; w != 0; i ++) {
        for (y = 1; y != w; y ++)
            *list = (*list)->next;
        line = malloc(sizeof(char) *
                    (my_strlen(nbr_print(i)) + my_strlen((*list)->str) + 2));
        line = my_strcat(nbr_print(i), " ");
        line = my_strcat(line, (*list)->str);
        *list = *history;
        write(fd, line, my_strlen(line));
        free_line(line);
        w --;
    }
}

int error_log(hist_t *history)
{
    int fd = creat("logs/last.log", 00777);
    hist_t *list = history;

    if (fd == END || list == NULL || list->str == NULL)
        return (ERROR);
    cpy_log(&list, &history, fd);
    close(fd);
    return (SUCCESS);
}
