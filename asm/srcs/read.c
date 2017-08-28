/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/08/28 15:59:10 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_encoding_byte(t_src_line *lines)
{
	int	i;

	i = 0;
	while (lines[i].data != NULL)
	{
		i++;
	}
	return (EXIT_SUCCESS);
}

int		get_raw_data(t_src_line *lines, int fd)
{
	int	i;

	i = 0;
	while (i < MAX_LINES && get_next_line(fd, &line) > 0)
	{
		lines[i].data = line;
		i++;
	}
	if (i == MAX_LINES)
	{
		ft_putendl_fd("Too many lines in file", 2);
		return (EXIT_FAILURE);
	}
	lines[i].data = NULL;
	return (EXIT_SUCCESS);
}

int		assemble(int fd)
{
	char	*line;
	t_src_line lines[MAX_LINES];

	if (get_raw_data(lines, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
