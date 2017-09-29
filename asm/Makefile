# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/28 15:46:22 by dbarrow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRCS = srcs/*.c

FLAGS = -g -g3 -Wall -Werror -Wextra -iquoteincludes

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) ../libft/libft.a -iquoteincludes $(FLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf asm.dSYM

re: fclean all

test:
	./asm testfile.s
