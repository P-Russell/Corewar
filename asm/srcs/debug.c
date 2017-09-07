/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:05:54 by prussell          #+#    #+#             */
/*   Updated: 2017/09/07 10:07:05 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_struct(t_src_line *lines)
{
	int	i;

	i = 0;
	printf("----------------------------\n");
	while (i < MAX_LINES && (lines[i].opcode || lines[i].label))
	{
		printf("index number %d\n", i);
		if (lines[i].label)
			printf("label: %s\n", lines[i].label);
		else
		{
			printf("opcode num: %d, name: %s\n", lines[i].opcode, g_op_tab[lines[i].opcode - 1].name);
		}
		printf("----------------------------\n");
		i++;
	}
}

