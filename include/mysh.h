/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Include file
*/

#ifndef sh42_H_
#define sh42_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "minishell_struct.h"
#include "lib.h"
#include "minishell2.h"
#include "my_printf.h"
#include "macros.h"
#include "my.h"
#include "get_next_line.h"

int my_shell(char **env);
void new_com(void);

//tools
char *forloc(char *str);
int env_length(char **arr);
char **find_old_pwd(char *str, char *new_env[]);
char **modif_arr(char **arr, char *new_env[]);
char *find_pwd(void);
void display_error(char* msg, char *var);
void start_prompt_shell(int *is_eof, char **user_input, size_t *size);

int my_exec(tree_t *tree, char *new_env[]);
void move_while_pipe(tree_t **tree);
int do_pipes(tree_t *tree, char ***env, hist_t *history);
void exec_pipes_norm(tree_t **tree, int **pipes_fd, int prev_fd, int r);

char *my_get_environment(char *new_env[], char *str);
int exec_redirect(tree_t *tree, int *pipes_fd, int prev_fd);
int my_echo(char ***env, char **arg);
char *my_get_environment(char *new_env[], char *str);
int print_echo(char **args, char ***env);
int echo_var_len(char *arg, int i);
int if_redirection(tree_t *tree);

int print_hist(hist_t *history);
hist_t *new_comm(char *com, hist_t *history);
int sup_gestion(tree_t *tree, int *pipes_fd, int prev_fd);
int exec_redirect(tree_t *tree, int *pipes_fd, int prev_fd);
int inf_gestion(tree_t *tree, int *pipes_fd, int prev_fd);
int is_redirect_or_pipe(char *c);
int exec_builtin(char **args, char ***env, hist_t *history);

int check_next_redirect(tree_t *tree, int *pipes_next,
    int *pipes_fd, int prev_fd);
void select_command_check_line(char *line, tree_t **tree,
        int *status, char **env);
int output_int(char *str);
int is_redirect_or_pipe(char *c);
void display_error(char* msg, char *var);
void display_tree(tree_t *tree);
int after_exec_gestion(tree_t *tree, int pid, int status, int copy_and);
void norm_exec(tree_t *tree, int *pipes_fd, int prev_fd, int r);
int is_a_builtin(char *command);
int error_log(hist_t *history);
int exec_all(tree_t *tree, all_t *all_thing);
hist_t *rm_history(hist_t *history, char *str);
char **separator(char *commands, char **env, hist_t *history);
int check_bin(char *str, char *str2);
int cd_old(char **new_env[], char **arr);
char **find_filepath(char **arr, char *new_env[]);
int check_filepath(char **arr);
int check_exec(char *str, char *str2);
int if_forking(tree_t *tree);
int is_problem(tree_t *tree, all_t *all_thing);
int is_modifing_env(char *command);
#endif
