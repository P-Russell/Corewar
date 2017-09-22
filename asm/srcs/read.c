/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/09/21 16:32:51 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		extract_loop(t_norm *n, char **split, t_src_line *lines)
{
	while (*split)
	{
		if (is_comment(*split))
			break ;
		else if (is_label_address(*split) && (n->label_found = 1))
			lines->label = ft_strdup(*split);
		else if (is_opcode(*split) && (n->op_code_found = 1))
			lines->opcode = is_opcode(*split);
		else if (is_param(*split) && n->i < MAX_ARGS_NUMBER &&
				(n->params_found = 1))
			lines->params[n->i++] = ft_strdup(*split);
		else
		{
			ft_putendl("Something's wrong");
			exit(-7);
		}
		split++;
	}
}

int			extract_data_from_line(char **split, t_src_line *lines)
{
	t_norm	n;

	n.label_found = 0;
	n.op_code_found = 0;
	n.params_found = 0;
	n.i = 0;
	extract_loop(&n, split, lines);
	if (n.op_code_found == 0 && n.label_found == 0)
	{
		ft_putendl_fd("Wrong opcode somewhere", 2);
		exit(-6);
	}
	return (1);
}

int			get_data(t_src_line *lines, int fd)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (i < MAX_LINES && get_next_line(fd, &line) > 0)
	{
		if (*line && (split = core_line_split(line)) && is_code_line(split))
		{
			extract_data_from_line(split, lines + i);
			ft_matrixdel((void **)split);
			lines[i].num = i;
			i++;
		}
		ft_strdel(&line);
	}
	if (i == MAX_LINES)
	{
		ft_putendl_fd("Lines in file exceed MAX_LINES", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void		init_line_struct(t_src_line *lines)
{
	int i;
	int	j;

	i = 0;
	while (i < MAX_LINES)
	{
		lines[i].label = NULL;
		lines[i].acb = 0;
		j = 0;
		while (j < MAX_ARGS_NUMBER)
			lines[i].params[j++] = NULL;
		lines[i].opcode = 0;
		lines[i].bytes = 0;
		i++;
	}
}

t_src_line	*build_line_data_struct(int fd)
{
	t_src_line lines[MAX_LINES];
	t_src_line *lines_ptr;

	lines_ptr = lines;
	init_line_struct(lines);
	if (get_data(lines, fd) == EXIT_FAILURE)
		return (NULL);
	if (get_acb(lines) == EXIT_FAILURE)
		return (NULL);
	if (get_bytes(lines) == EXIT_FAILURE)
		return (NULL);
	return (lines_ptr);
}
