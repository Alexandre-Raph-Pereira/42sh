/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell_struct
*/

#ifndef MINISHELL_STRUCT_H_
#define MINISHELL_STRUCT_H_

typedef struct tree_s {
    int is_token;
    char token[3];
    char *command;
    char **full_command;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct hist_s {
    char *str;
    struct hist_s *next;
} hist_t;

typedef struct all_s {
    char **envi;
    struct hist_s *history;
} all_t;

#endif
