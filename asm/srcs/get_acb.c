/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:40:11 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/22 16:10:06 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	set_params(t_src_line *lines)
{
	int	i;
	int	p;

	i = 0;
	while (lines[i].num >= 0)
	{
		p = 0;
		while (lines[i].param_type[p] != 0)
		{
			if (lines[i].param_type[p] == 3)
				lines[i].param_type[p] = 4;
			p++;
		}
		i++;
	}
	return (0);
}

int	calculate_acb(t_src_line *line)
{
	int	square;
	int	n;
	int	p;

	n = 0;
	square = 8;
	while (n < MAX_ARGS_NUMBER && line->params[n])
	{
		if (line->params[n][0] == 'r')
			line->param_type[n] = REG_CODE;
		else if (ft_strchr(line->params[n], '%') != NULL)
			line->param_type[n] = DIR_CODE;
		else if (ft_isnumber(line->params[n]))
			line->param_type[n] = IND_CODE;
		else
			p = 0;
		line->acb += line->param_type[n] * (square * square);
		square /= 2;
		n++;
	}
	return (EXIT_SUCCESS);
}

int	get_acb(t_src_line *lines)
{
	int	i;
	int	n;

	i = 0;
	while (lines[i].num >= 0)
	{
		n = 0;
		while (g_op_tab[n].opcode != 0 && g_op_tab[n].opcode != lines[i].opcode)
			n++;
		if (n == 16)
			;
		else if (g_op_tab[n].has_pcode == 1)
			calculate_acb(lines + i);
		i++;
	}
	return (EXIT_SUCCESS);
}
