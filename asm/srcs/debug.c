/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:05:54 by prussell          #+#    #+#             */
/*   Updated: 2017/09/08 11:33:31 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_struct(t_src_line *lines)
{
	int	i;

	i = 0;
	printf("----------------------------\n");
	while (i < MAX_LINES)
	{
		printf("index number %d\n", i);
		if (lines[i].label)
			printf("label: %s\n", lines[i].label);
		if (lines[i].opcode)
			printf("opcode num: %d, name: %s\n", lines[i].opcode, g_op_tab[lines[i].opcode - 1].name);
		int j = 0;
		while (lines[i].params[j])
		{
			printf("param %d: %s\n", j + 1, lines[i].params[j]);
			j++;
		}
		printf("acb: %d\n", lines[i].acb);
		printf("num bytes: %d\n", lines[i].bytes);
		printf("----------------------------\n");
		i++;
	}
}

