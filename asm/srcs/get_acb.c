/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:40:11 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/08 11:35:59 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	calculate_acb(t_src_line *line)
{
	int	square;
	int	n;
	int	p;

	n = 0;
	square = 8;
	while (n < MAX_ARGS_NUMBER)
	{
		if (ft_strchr(line->params[n], 'r') != NULL)
			p = REG_CODE;
		else if (ft_strchr(line->params[n], '%') != NULL)
			p = IND_CODE;
		else if (ft_isnumber(line->params[n]))
			p = DIR_CODE;
		else
			p = 0;
		line->acb += p * (square * square);
		square /= 2;
		n++;
	}
	return (EXIT_SUCCESS);
}

int	get_acb(t_src_line *lines)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < MAX_LINES)
	{
		while (g_op_tab[n].opcode != 0 && g_op_tab[n].opcode != lines[i].opcode)
			n++;
		if (g_op_tab[n].has_pcode == 1)
			calculate_acb(lines + i);
		n = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}
