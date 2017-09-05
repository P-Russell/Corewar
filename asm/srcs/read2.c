/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/09/05 15:23:53 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_data(t_src_line *lines, int fd)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (i < MAX_LINES && get_next_line(fd, &line) > 0)
	{
		if (!is_comment(line) && *line && (split == ft_splitspace(line)))
		{
			if (is_label(split[0]))
			{
				lines[i].label = ft_strdup(split[0]);
			}
			if (split[1] && is_opcode(split[1]))
				lines[i].opcode = is_opcode(split[1]);
			ft_matrixdel((void **)split);
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

void	init_line_struct(t_src_line *lines)
{
	int i;
	int	j;

	i = 0;
	while (i < MAX_LINES)
	{
		lines[i].data = NULL;
		lines[i].label = NULL;
		lines[i].acb = 0;
		j = 0;
		while (j < MAX_ARGS_NUMBER)
			lines[i].params[j++] = 0;
		lines[i].opcode = 0;
		lines[i].bytes = 0;
		i++;
	}
}

int		assemble(int fd)
{
	char	*line;
	t_src_line lines[MAX_LINES];

	init_line_struct(lines);
	if (get_data(lines, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	print_struct(lines);
	return (EXIT_SUCCESS);
}
