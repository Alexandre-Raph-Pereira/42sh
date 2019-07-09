/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** Splits a string into words
*/

#include <stdlib.h>

static int is_alphanum(char c)
{
    if (c < 33)
        return (0);
    return (1);
}

int word_size(char const *str, int first_letter, char c)
{
    int i = 0;

    while (is_alphanum(str[first_letter + i]) && str[first_letter + i] != c)
        i++;
    return (i);
}

char *copy_word(char const *str, char *str_array, int first_l, int size)
{
    int i = 0;

    while (i < size) {
        str_array[i] = str[first_l + i];
        i++;
    }
    str_array[i] = '\0';
    return (str_array);
}

int get_nbr_words(char const *str, char c)
{
    int size = 0;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (is_alphanum(str[i]) && str[i] != c) {
            size = word_size(str, i, c);
            i = i + size;
            j++;
        }
        else
            i++;
    }
    return (j);
}

char **my_str_to_word_array(char const *str, char c)
{
    char **str_array = NULL;
    int i = 0;
    int j = 0;
    int size = 0;

    str_array = malloc(sizeof(char *) * (get_nbr_words(str, c) + 1));
    while (str[i] != '\0') {
        if (is_alphanum(str[i]) && str[i] != c) {
            size = word_size(str, i, c);
            str_array[j] = malloc(sizeof(char) * (size + 1));
            copy_word(str, str_array[j], i, size);
            i += size;
            j++;
        }
        else
            i++;
    }
    str_array[j] = NULL;
    return (str_array);
}
