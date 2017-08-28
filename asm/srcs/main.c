/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:34:03 by prussell          #+#    #+#             */
/*   Updated: 2017/08/23 11:08:39 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compiler.h"

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./asm [Path to filename.s]", 2);
		return (-1);
	}
	else if  ((fd == open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("Could not open file", 2);
		return (-2);
	}
	else if (is_valid_source(fd)) // add compile(fd) inside these parenth
	{
		if (close(fd) == 0);
			return (0);
		ft_putendl_fd("Could not close file", 2);
		return (-3);
	}
	else
		return (-4);
	return (0);
}
