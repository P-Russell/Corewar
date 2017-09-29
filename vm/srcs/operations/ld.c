/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:26:01 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/29 09:37:23 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		op_ld(t_process *p, t_core *arena)
{
	int load_val;
	int acb;
	int	chk;

	acb = (arena[(p->pc + 1) % MEM_SIZE].raw);
	p->pc = (p->pc + 2) % MEM_SIZE;
	if (is_direct(acb, 1) == 1)
		load_val = data_var(p->pc, arena, REG_SIZE);
	else if (is_indirect(acb, 1) == 1)
		load_val = data_var((p->pc + (data_var(p->pc, arena, IND_SIZE) %
						IDX_MOD)) % MEM_SIZE, arena, IND_SIZE);
	chk = (is_direct(acb, 1) == 1 || is_indirect(acb, 1) == 1) ? 1 : 0;
	p->pc = pc_counter(p->pc, acb, 1);
	if (chk == 1 && is_register(acb, 2) == 1 && valid_reg(arena[(p->pc)
				% MEM_SIZE].raw))
	{
		chk++;
		write_to_reg(p->reg[data_var(p->pc, arena, T_REG)], load_val);
	}
	p->pc = pc_counter(p->pc, acb, 2);
	p->carry = (chk == 2) ? 1 : 0;
	if (chk == 2)
		return (1);
	return (0);
}
