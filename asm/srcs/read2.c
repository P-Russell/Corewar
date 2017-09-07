/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/09/05 15:53:35 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	num_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_params(t_src_line *lines)
{
	int		i;
	int		n;
	int		p;
	char	**split;

	n = 0;
	i = 0;
	p = 0;
	while (i < 2)
	{
		split = core_line_space(lines[i].data);
		if (ft_strchr(split[0], LABEL_CHAR) != NULL)
		{
			lines[i].label = ft_strdup(split[0]);
			n++;
		}
		n++;
		while (split[n])
		{
			if (ft_strstr(split[n], "r") != NULL)
				lines[i].param_type[p] = 1;
			else if (ft_strstr(split[n], "%") != NULL)
				lines[i].param_type[p] = 3;
			else if (num_check(split[n]))
				lines[i].param_type[p] = 2;
			else
				lines[i].param_type[p] = 0;
			p++;
			n++;
		}
		free(split);
		p = 0;
		n = 0;
		i++;
	}
	return (0);
}

int		get_data(t_src_line *lines, int fd)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (i < MAX_LINES && get_next_line(fd, &line) > 0)
	{
		if (!is_comment(line) && *line && (split == core_line_split(line)))
		{
			if (is_label(split[0]))
			{
				lines[i].label = ft_strdup(split[0]);
			}
			if (split[1] && is_opcode(split[1]))
			{
				lines[i].opcode = is_opcode(split[1]);

			}
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
