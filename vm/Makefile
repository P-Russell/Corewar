# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/19 11:00:19 by prussell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = srcs/main.c srcs/init_env.c srcs/init_arena.c

FLAGS = -g3 -Wall -Werror -Wextra -iquoteincludes

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) ../libft/libft.a -iquoteincludes $(FLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
