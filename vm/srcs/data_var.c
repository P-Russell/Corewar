/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 07:57:54 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 16:17:34 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t	get_val(int pc, t_core *arena)
{
	int32_t	ans;

	ans = arena[pc].raw & 0xFF;
	ans = ans << 8;
	ans = ans + arena[(pc + 1) % MEM_SIZE].raw & 0xFF;
	ans = ans << 8;
	ans = ans + arena[(pc + 2) % MEM_SIZE].raw & 0xFF;
	ans = ans << 8;
	ans = ans + arena[(pc + 3) % MEM_SIZE].raw & 0xFF;
	return (ans);
}

int		data_var(int pc, t_core *arena, size_t s)
{
	t_data	var;
	int		ans;

	ans = 0;
	if (s == 1)
	{
		var.byte_1 = arena[pc].raw;
		ans = var.byte_1;
	}
	else if (s == 4)
	{
		var.byte_4 = get_val(pc, arena);
		ans = var.byte_4;
	}
	else if (s == 2)
	{
		var.byte_2 = value_from_core(arena, pc, (int)s);
		ans = var.byte_2;
	}
	return (ans);
}
