/*
** EPITECH PROJECT, 2019
** MiniShell
** File description:
** Environnement's variables
*/

#include "mysh.h"

void new_com(void)
{
    char *user = getlogin();
    char *locat = getcwd(NULL, 0);

    if (locat == NULL)
        locat = my_strcpy("~");
    else {
        locat = forloc(locat);
        if (locat == NULL)
            locat = my_strcpy("~");
    }
    my_printf("\e[36m");
    my_printf("[%s@localminishell %s] ", user, locat);
    my_printf("\e[0m");
}
