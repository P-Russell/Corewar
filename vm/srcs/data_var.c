/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 07:57:54 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 10:11:41 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int16_t	get_val(int pc, t_core *arena)
{
	int16_t	ans;

	ans = arena[pc].raw;
	ans = ans << 8;
	ans = ans + arena[(pc + 1) % MEM_SIZE].raw;
	return (ans);
}

int		data_var(int pc, t_core *arena, size_t s)
{
	t_data	var;
	int		ans;

	if (s == 1)
	{
		var.byte_1 = arena[pc].raw;
		ans = var.byte_1;
	}
	else if (s == 2)
	{
		var.byte_2 = get_val(pc, arena);
		ans = var.byte_2;
	}
	else
	{
		var.byte_4 = value_from_core(arena, pc, (int)s);
		ans = var.byte_4;
	}
	return (ans);
}
/*
int		value_from_reg(unsigned char *reg)
{
	int32_t ans;
	int		i;
	int		t;
	
	i = 0;
	ans = 0;
	while (i < REG_SIZE)
	{
		ans += reg[i];
		ans = ans << 1;
		i++;
	}
	t = ans;
	return (t);
}*/
