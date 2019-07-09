/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** Main function
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    return (my_shell(env));
}
