/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/09/04 16:13:52 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_src_line		*get_acb(t_src_line *lines)
{
	int	i;
	int	square;
	int	n;

	i = 0;
	n = MAX_ARGS_NUMBER;
	while (lines[i].data != NULL)
	{
		lines[i].acb = 0;
		while (lines[i].params[n])
		{
			lines[i].acb += lines[i].params[n] * (square * square);
			square /= 2;
			n--;
		}
		i++;
	}
	return (lines);
}

t_src_line		*get_params(t_src_line *lines)
{
	int		i;
	int		n;
	int		p;
	char	**split;

	n = 0;
	i = 0;
	p = 0;
	while (lines[i].data != NULL)
	{
		split = ft_strsplit(lines[i].data, ' ');
		if (ft_strchr(split[0], LABEL_CHAR) != NULL)
		{
			lines[i].label = split[0];
			n++;
		}
		n++;
		while (split[n])
		{
			if (ft_strstr(split[n], "r") != NULL)
				lines[i].params[p] = 1;
			else if (ft_strstr(split[n], "%") != NULL)
				lines[i].params[p] = 3;
			else if (ft_isdigit(ft_atoi(split[n])))
				lines[i].params[p] = 2;
			else
				lines[i].params[p] = 0;
			p++;
			n++;
		}
		free(split);
		i++;
	}
	return (lines);
}
/*
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
}*/
