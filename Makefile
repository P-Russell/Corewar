# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/13 09:09:31 by prussell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

all: $(NAME)

$(NAME):

asm:
	make -C asm/ fclean

vm:
	make -C vm/ fclean && make -C /vm

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean
