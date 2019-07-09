/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** strlib
*/

#ifndef STRLIB_H_
#define STRLIB_H_

int my_strcmp(char const *str1, char const *str2);
int my_strlen(char const *str);
char *my_strcpy(char const *str);
char **my_str_to_word_array(char const *str, char c);
char *my_strcat(char *dest, char const *src);
char *my_strmcat(char const *str1, char const *str2);
char *my_strntoncpy(char *str, int start, int size);
char *my_strdup(char const *src);
int my_cmp(char const *str1, char const *str2);
int my_strstr(char *str, char const *to_find);
char *beautifull_str(char *str);
#endif /* !STRLIB_H_ */
