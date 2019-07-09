##
## EPITECH PROJECT, 2019
## PSU_42sh_2018
## File description:
## Makefile
##

CC		=		gcc -o

CFLAGS	+=		-Wall -Wextra

RM		=		rm -f

SRCS	=		my_str_to_word_array.c	\
				my_strcat.c				\
				my_strcmp.c				\
				my_strcpy.c				\
				my_strlen.c				\
				my_strmcat.c			\
				my_putstr2.c			\
				my_str_to_array.c		\
				my_cpy.c				\
				my_strdup.c				\
				my_strntoncpy.c			\
				my_strstr.c 			\
				my_str_isnum.c 			\
				my_str_isprintable.c	\
				my_getnbr.c 			\
				beautifullstr.c			\
				my_putint_in_str.c		\
				my_revstr.c				\

OBJS	=		$(SRCS:.c=.o)

NAME	=		libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
