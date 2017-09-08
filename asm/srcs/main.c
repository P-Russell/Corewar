/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:34:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/08 10:09:44 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./asm [Path to filename.s]", 2);
		return (-1);
	}
	else if ((fd = open(argv[1], O_RDONLY)) < 1)
	{
		ft_putendl_fd("Could not open file", 2);
		return (-2);
	}
	else if (is_valid_fd(fd)) 
	{
		assemble(fd);
		if (close(fd) == 0)
			return (0);
		ft_putendl_fd("Could not close file", 2);
		return (-3);
	}
	else
		return (-4);
	return (0);
}
