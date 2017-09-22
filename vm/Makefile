# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/22 11:15:39 by prussell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = srcs/*.c
OPER = srcs/operations/*.c

FLAGS = -Wall -Werror -Wextra -iquoteincludes

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) $(OPER) ../libft/libft.a -iquoteincludes $(FLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
