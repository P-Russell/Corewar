/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:52:40 by prussell          #+#    #+#             */
/*   Updated: 2017/09/08 08:53:41 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		extract_data_from_line(char **split, t_src_line *lines)
{
	int		label_found;
	int		op_code_found;
	int		params_found; 
	int		i;

	label_found = 0;
	op_code_found = 0;
	params_found = 0;
	i = 0;
	while (*split)
	{
		if (is_comment(*split))
			break ;
		else if (is_label_address(*split) && (label_found = 1))
		{
			printf("label found %s\n", *split);
			lines->label = ft_strdup(*split);
		}
		else if (is_opcode(*split) && (op_code_found = 1))
		{
			printf("opcode found %s\n", *split);
			lines->opcode = is_opcode(*split);
		}
		else if (is_param(*split) && i < MAX_ARGS_NUMBER && (params_found = 1))
		{
			printf("param found %s\n", *split);
			lines->params[i] = ft_strdup(*split);
		}
		split++;
	}
	return (1);
}

int		get_data(t_src_line *lines, int fd)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (i < MAX_LINES && get_next_line(fd, &line) > 0)
	{
		if (*line && !is_comment(line) && (split = core_line_split(line)))
		{
			int j = 0;
			printf ("From line: ");
			while (split[j])
				printf(" %s", split[j++]);
			printf("\n");
			extract_data_from_line(split, lines + i);
			ft_matrixdel((void **)split);
			i++;
		}
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
			lines[i].params[j++] = NULL;
		lines[i].opcode = 0;
		lines[i].bytes = 0;
		i++;
	}
}

int		assemble(int fd)
{
	t_src_line lines[MAX_LINES];

	init_line_struct(lines);
	if (get_data(lines, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_acb(lines) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_bytes(lines) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	print_struct(lines);
	return (EXIT_SUCCESS);
}
