 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:24:03 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/27 15:06:03 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		add(t_process *p, t_core *arena)
{
	int	i;
	int param[3];
	int	acb;

	p->pc = (p->pc + 1) % MEM_SIZE;
	acb = (arena[p->pc].raw);
	p->pc = (p->pc + 1) % MEM_SIZE;
	i = 0;
	while (i < 3)
	{
		if (is_register(acb, i) == 1 &&
				valid_reg(arena[(p->pc + i) % MEM_SIZE].raw))
			i++;
		else
			break ;
	}
	p->cycles_to_exec =  g_op_tab[arena[(p->pc + 3) % MEM_SIZE].raw].nb_cycles;
	if (i == 3)
	{
		param[0] = value_from_reg(p->reg[arena[p->pc].raw]);
		param[1] = value_from_reg(p->reg[arena[(p->pc + 1) % MEM_SIZE].raw]);
		param[2] = arena[(p->pc + 2) % MEM_SIZE].raw;
		write_to_reg(p->reg[param[2]], param[0] + param[1]);
		p->pc = (p->pc + 3) % MEM_SIZE;
	}
	else
	{
		p->pc = (p->pc + 3) % MEM_SIZE;
		return (0);
	}
	p->carry = 1;
	return (1);
}

int		add(t_process *p, t_core *arena)
{
	t_op_var	var;

	var.acb = data_var((p->pc + 1 % MEM_SIZE), arena, T_REG);
	init_var(&var);
	var.param[0] = data_var((p-pc + 2) % MEM_SIZE, arena, T_REG);
	var.param[1] = data_var((p-pc + 2 + T_REG) % MEM_SIZE, arena, T_REG);
	var.param[2] = data_var((p-pc + 2 + T_REG * 2) % MEM_SIZE, arena, T_REG);
	if (acb != 84 || !valid_reg(var.params[0]) || !valid_reg(var.params[1]) ||
					!valid_reg(var.params[2]))
	{
		p->pc = (pc + (T_REG * 3) + 1) % MEM_SIZE;
		p->carry = 0;
		return (0);
	}
	write_to_reg(p->reg[var.param[3]], value_from_reg(p->reg[var.param[2]])
			+ value_from_ref(p->reg[var.param[2]]));
	p->carry = 1;
	p->pc = (pc + (T_REG * 3) + 1) % MEM_SIZE;
	return (1);
}
