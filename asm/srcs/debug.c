/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:05:54 by prussell          #+#    #+#             */
/*   Updated: 2017/09/05 12:42:47 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

void	print_struct(t_src_line *lines)
{
	int	i;

	i = 0;
	printf("----------------------------\n");
	while (i < MAX_LINES && (lines[i].opcode || lines[i].label))
	{
		printf("index number %d\n", i);
		if (lines[i].label)
			printf("lable: %s\n", lines[i].label);
		else
		{
			printf("opcode num: %d, name: %s\n", lines[i].opcode, op_tab[lines[i].opcode - 1].name);
		}
		printf("----------------------------\n");
		i++;
	}
}

