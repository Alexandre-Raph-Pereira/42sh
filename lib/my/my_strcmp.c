/*
** EPITECH PROJECT, 2019
** n4s_package
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int my_cmp(char const *str1, char const *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (-1);
        i++;
    }
    return (0);
}

int my_strcmp(char const *str1, char const *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (-1);
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (-1);
    return (0);
}