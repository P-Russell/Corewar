/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 07:57:54 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/28 10:18:27 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int16_t	get_val(int pc, t_core *arena)
{
	int16_t	ans;

	ans = arena[pc].raw;
	ans = ans << 4;
	ans = ans + arena[(pc + 1) % MEM_SIZE].raw;
	return (ans);
}

int		data_var_pc(int *pc, t_core *arena, size_t s)
{
	t_data	var;
	int		ans;

	if (s == T_REG)
	{
		var.byte_1 = arena[*pc].raw;
		*pc = (*pc + T_REG) % MEM_SIZE;
		ans = var.byte_1;
	}
	else if (s == T_DIR)
	{
		var.byte_2 = get_val(*pc, arena);
		*pc = (*pc + T_DIR) % MEM_SIZE;
		ans = var.byte_2;
	}
	else
	{
		var.byte_4 = value_from_core(arena, *pc, (int)s);
		*pc = (*pc + T_IND) % MEM_SIZE;
		ans = var.byte_4;
	}
	return (ans);
}
