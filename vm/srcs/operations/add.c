 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:24:03 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/26 08:11:03 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		add(t_process *p, t_core *arena)
{
	int	i;
	int param1;
	int param2;
	int	param3;
	int	acb;

	p->pc = (p->pc + 1) % MEM_SIZE;
	acb = (arena[p->pc].raw);
	p->pc = (p->pc + 1) % MEM_SIZE;
	param1 = value_from_reg(p->reg[arena[p->pc].raw]);
	p->pc = (p->pc + 1) % MEM_SIZE;
	param2 = value_from_reg(p->reg[arena[p->pc].raw]);
	p->pc = (p->pc + 1) % MEM_SIZE;
	param3 = value_from_reg(p->reg[arena[p->pc].raw]);
	p->pc = (p->pc + 1) % MEM_SIZE;
	write_to_reg(p->reg[param3], param1 + param2);
	p->cycles_to_exec =  g_op_tab[arena[p->pc].raw - 1].nb_cycles;
	return (0);
}
