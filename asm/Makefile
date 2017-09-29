# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/29 10:21:56 by dbarrow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRCS = srcs/check.c srcs/check2.c srcs/error_checker.c srcs/file_size.c \
	srcs/get_acb.c srcs/get_bytes.c srcs/header.c srcs/line_handling.c \
	srcs/main.c srcs/op.c srcs/print_error.c srcs/read.c srcs/write.c \
	srcs/write2.c srcs/write_functions.c

FLAGS = -g -g3 -Wall -Werror -Wextra -iquoteincludes

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) ../libft/libft.a -iquoteincludes $(FLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf asm.dSYM

re: fclean all

