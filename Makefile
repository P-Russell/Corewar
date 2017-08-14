# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/08/14 16:02:52 by prussell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = vm_srcs/*.c

FLAGS = -g3 -Wall -Werror -Wextra -iquotevm_includes

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) libft/libft.a -iquoteincludes $(FLAGS)

exe:
	gcc -o $(NAME) $(SRCS) libft/libft.a -iquoteincludes $(FLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean
