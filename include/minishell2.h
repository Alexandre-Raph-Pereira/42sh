/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell2
*/

#ifndef minishell2_H_
#define minishell2_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"
#include "minishell_struct.h"
#include "lib.h"
#include "macros.h"

char **my_cd(char **env, char **args);
int cd_function(char **new_env[], char **args);
void exec_env(char **evn);
char **select_command(char *line, char **env, hist_t *history);
int my_setenv(char ***env, char *var, char *val);
int compare_vars(char const *var, char const *arg);
int copy_env(char **new_env, char **env, char *var, char *val);
int count_lines(char **env);
char **dup_env(char **env);
int exec_setenv(char ***env, char **args);
int my_exit(char ***env, char **args);
int my_unsetenv(char ***env, char **args);
void free_env(char **env);
int exec_unsetenv(char ***env, char **args);
char *my_getenv(char **env, char *var_name);
void free_array(char **array);
char *search_command(char **args, char **env, tree_t *left);
int check_str_is_alphanum(char *str);
int has_redirections(tree_t *tree);

// Command execution
int exec_commands(tree_t *tree, char ***env, hist_t *history);
int get_number_of_pipes(tree_t *tree);
char get_token_in_tree(tree_t *tree);
int jump_wrong_commands(tree_t **tree);
int check_wrong_commands(tree_t *tree);

// Parser
int is_token(char *line, int i);
int get_command_size(char *line);
char *get_command(char *line);
tree_t *parse_line(char *line, char **env);

// Binary tree
tree_t *create_token_tree(char *token, int i);
tree_t *create_command_tree(char *command, char **env, tree_t *left);
int add_token_to_tree(tree_t *tree, char *token, int i);
int add_command_to_tree(tree_t *tree, char *command, char **env, tree_t *left);
void free_tree(tree_t *tree);

// Messages
void display_not_found(char *command);
void display_access_denied(char *command);

int exec_redirect(tree_t *tree, int *pipes_fd, int prev_fd);
int status_gestion(int status);
int error_redirect(tree_t *tree);
#endif /* !minishell2_H_ */
