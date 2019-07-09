/*
** EPITECH PROJECT, 2018
** my_str_isprintable.c
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < ' ' || str[i] > '~')
            && str[i] != '\t' && str[i] != '\n')
            return (-1);
    return (0);
}
