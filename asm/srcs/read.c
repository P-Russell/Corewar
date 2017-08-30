/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/08/30 10:12:26 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_line_lable(char *line)
{
	int	i;
	while (line[i])
	return (EXIT_SUCCESS);
}

int		calc_line_bytes(t_src_line line)
{
	return (0);
}

int		*get_params(char *lines)
{
	int		params[MAX_ARGS_NUMBER];
	int		i;

	while
}

int		get_acb(char *lines)
{
	int	i;

	i = 0;
	while (lines[i].data != NULL)
	{
		i++;
	}
	return (0);
}

int		get_raw_data(t_src_line *lines, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < MAX_LINES && get_next_line(fd, &line) > 0)
	{
		if (!is_comment(line))
		{
			lines[i].data = line;
			i++;
		}
		else
			ft_strdel(&line);
	}
	if (i == MAX_LINES)
	{
		ft_putendl_fd("Lines in file exceed MAX_LINES", 2);
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
