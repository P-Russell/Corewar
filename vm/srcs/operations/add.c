 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:24:03 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/26 16:02:24 by prussell         ###   ########.fr       */
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
