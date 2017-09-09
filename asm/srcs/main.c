/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:34:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/09 13:03:02 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	int	fd;
	t_binary bin;
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_putendl_fd("Usage: ./asm [Path to filename.s] ...", 2);
		return (-1);
	}
	else if ((fd = open(argv[i], O_RDONLY)) < 1)
	{
		ft_putendl_fd("Could not open file", 2);
		return (-2);
	}
	else if (is_valid_fd(fd)) 
	{
		init_bin_var(&bin, fd, argv[i]);
		lseek(fd, 0, SEEK_SET);
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
