/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:14:43 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/08 08:35:16 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	get_bytes(t_src_line *lines)
{
	int	i;
	int	n;
	int	p;

	i = 0;
	n = 0;
	while (lines[i].label != NULL || lines[i].opcode == 0)
	{
		if (lines[i].opcode != 0)
		{
			while (g_op_tab[n].opcode != lines[i].opcode)
				n++;
			p = 0;
			while (p < g_op_tab[n].nb_params)
			{
				if (ft_strchr(lines[i].params[p], DIRECT_CHAR) &&
						g_op_tab[n].has_idx == 0)
					lines[i].bytes += DIR_SIZE;
				else if (ft_strchr(lines[i].params[p], DIRECT_CHAR)
						&& g_op_tab[n].has_idx == 1)
					lines[i].bytes += IND_SIZE;
				else if (ft_strchr(lines[i].params[p], 'r') != NULL)
					lines[i].bytes += REG_SIZE;
				else if (ft_isnumber(lines[i].params[p]))
					lines[i].bytes += IND_SIZE;
				p++;
			}
		}
		i++;
		n = 0;
	}
	return (EXIT_SUCCESS);
}
