##
## EPITECH PROJECT, 2019
## CPE_minishell2_2018
## File description:
## Makefile
##

FCOM			=	src/commands/
FHIS			=	src/history/
FTRE			=	src/binary_tree/
FTES			=	./tests/

CC				=	gcc

CPPFLAGS		=	-I./include/

RM				=	rm -f

TESTS_FLAGS     =   --coverage -lcriterion

INCLUDELIB		=	-L./lib/my/ -lmy -L./lib/my_printf -lmy_printf

SRCS			=	$(FHIS)history.c					\
					$(FHIS)rm_history.c					\
					src/my_cd.c							\
					src/env.c			    			\
					src/setenv.c		    			\
					src/dup_env.c		    			\
					src/exec_setenv.c		    		\
					src/unsetenv.c		    			\
					src/free_env.c		    			\
					src/search_command.c	    		\
					src/my_getenv.c		    			\
					src/free_array.c		    		\
					src/select_command.c				\
					src/parser.c						\
					src/compare_vars.c	    			\
					src/retreive_command.c				\
					src/is_alphanum.c					\
					src/jump_redirections.c				\
					$(FTRE)binary_tree.c				\
					$(FTRE)create_tree.c				\
					$(FTRE)free_tree.c					\
					$(FCOM)command_exec.c				\
					$(FCOM)get_number_of_pipes.c		\
					$(FCOM)get_token_in_tree.c			\
					$(FCOM)jump_wrong_commands.c		\
					$(FCOM)pipes.c						\
					$(FCOM)pipes_norm.c					\
					$(FCOM)check_tokens.c				\
					src/prompt.c						\
					src/lf.c							\
					src/cd_function.c 					\
					src/my_echo.c 						\
					src/print_echo.c 					\
					src/pwd_gestion.c 					\
					src/env_function.c 					\
					src/exec_gestion.c 					\
					src/libs/my_str.c					\
					src/libs/my_lf_char.c				\
					src/libs/my_cut_str.c				\
					src/error_gestion.c 				\
					src/exec_redirection.c 				\
					src/my_exit.c 						\
					src/mysh.c	 						\
					src/check_next_redirection.c 		\
					src/get_next_line.c					\
					src/tools.c							\
					src/separator.c						\
					src/norm_exec.c 					\
					src/start_prompt_shell.c			\
					src/check_command_line.c			\
					src/log.c							\
					src/cd.c 							\

TESTS_SRCS		=	$(FTES)test_setenv.c	    		\
					$(FTES)test_unsetenv.c	    		\
					$(FTES)test_getenv.c	    		\
					$(FTES)test_select_command.c   	\
					$(FTES)test_env.c					\
					$(FTES)test_get_command.c			\
					$(FTES)test_lib.c					\
					$(FTES)test_tools.c				\

OBJ				=	$(SRCS:.c=.o)

NAME			=	42sh

TESTS_NAME		=	unit_tests

all: $(NAME)

$(NAME): 	$(OBJ)
	make -C ./lib/my_printf/
	make -C ./lib/my/
	$(CC) -o $(NAME) src/main.c $(OBJ) $(INCLUDELIB) $(CPPFLAGS)

clean:
	make clean -C ./lib/my_printf/
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my_printf/
	make fclean -C ./lib/my/
	$(RM) $(NAME)
	$(RM) $(TESTS_NAME)
	$(RM) *.gcno
	$(RM) *.gcda

re: fclean all

valgrind:	$(OBJ)
			make -C ./lib/my
			make -C ./lib/my_printf/
			$(CC) -o $(NAME) src/main.c $(OBJ) $(INCLUDELIB) $(CPPFLAGS)
			rm -f $(OBJ)
			valgrind ./$(NAME)

tests_run:
	make -C ./lib/my_printf/
	make -C ./lib/my/
	$(CC) -o $(TESTS_NAME) $(TESTS_SRCS) $(SRCS) $(CPPFLAGS) $(INCLUDELIB) $(TESTS_FLAGS)
	./$(TESTS_NAME)

covr:
	make -C ./lib/my_printf/
	make -C ./lib/my/
	$(CC) -o $(TESTS_NAME) $(TESTS_SRCS) $(SRCS) $(CPPFLAGS) $(INCLUDELIB) $(TESTS_FLAGS)
	./$(TESTS_NAME) ; gcovr

.PHONY:		all clean fclean re covr valgrind tests_run
