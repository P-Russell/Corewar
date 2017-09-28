/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:34:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/27 11:14:57 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_size(int fd)
{
	char	buffer[42];
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (read(fd, buffer, 42) != 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				n++;
			i++;
		}
	}
	lseek(fd, 0, SEEK_SET);
	return (n);
}

void	main_part_two(int fd, char **argv)
{
	t_src_line	*lines;
	t_binary	bin;
	int			n;

	n = get_size(fd);
	lines = build_line_data_struct(fd, n);
	lseek(fd, 0, SEEK_SET);
	init_bin_var(&bin, fd, argv[1]);
	champ_size(lines, &bin);
	if (close(fd) != 0)
	{
		ft_putendl_fd("Could not close file", 2);
		exit(-5);
	}
	if (check_errors(lines) == 1)
	{
		ft_putendl("Errors detected, aborting compilation");
		free(lines);
		exit(-4);
	}
	ft_putstr("No errors detected, Proceeding with compilation\n");
	write_cor(lines, &bin);
	free(lines);
}

int		main(int argc, char **argv)
{
	int			fd;

	if (argc == 1)
	{
		ft_putendl_fd("Usage: ./asm [Path to filename.s] ...", 2);
		return (-1);
	}
	else if ((fd = open(argv[1], O_RDONLY)) < 1)
	{
		ft_putendl_fd("Could not open file", 2);
		return (-2);
	}
	else if (is_valid_fd(fd))
	{
		main_part_two(fd, argv);
	}
	else
		return (-3);
	return (0);
}
