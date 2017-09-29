/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:30:21 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/29 10:30:26 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_add(t_process *p, t_core *arena)
{
	t_op_var	var;

	var.acb = data_var((p->pc + 1) % MEM_SIZE, arena, T_REG);
	init_var(&var);
	var.param[1] = data_var((p->pc + 2) % MEM_SIZE, arena, T_REG);
	var.param[2] = data_var((p->pc + 2 + T_REG) % MEM_SIZE, arena, T_REG);
	var.param[3] = data_var((p->pc + 2 + T_REG * 2) % MEM_SIZE, arena, T_REG);
	if (var.acb != 84 || !valid_reg(var.param[0]) || !valid_reg(var.param[1]) ||
					!valid_reg(var.param[2]))
	{
		p->pc = (p->pc + (T_REG * 3) + 1) % MEM_SIZE;
		p->carry = 0;
		return (0);
	}
	write_to_reg(p->reg[var.param[3]], value_from_reg(p->reg[var.param[1]])
			+ value_from_reg(p->reg[var.param[2]]));
	p->carry = 1;
	p->pc = (p->pc + (T_REG * 3) + 1) % MEM_SIZE;
	return (1);
}
