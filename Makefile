# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/25 09:58:48 by prussell          #+#    #+#              #
#    Updated: 2017/09/30 20:33:43 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: lib asmc vmc

asmc:
	@echo "Compile Asm"
	@make -C asm/ fclean && make -C asm/

vmc:
	@echo "Compile vm"
	@make -C vm/ fclean && make -C vm/

clean:
	make -C vm/ clean
	make -C asm/ clean

fclean:
	make -C vm/ fclean
	make -C asm/ fclean
	make -C libft/ fclean

re: fclean all

lib:
	@echo "Compile Libft"
	@make -C libft/ fclean && make -C libft/ && make -C libft/ clean
