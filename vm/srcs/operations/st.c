/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:44:07 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/29 16:05:42 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_st(t_process *p, t_core *arena)
{
	t_op_var	v;

	v.acb = arena[(p->pc + 1) % MEM_SIZE].raw;
	init_var(&v);
	v.p[1] = data_var((p->pc + 2) % MEM_SIZE, arena, v.t[1]);
	v.p[2] = data_var((p->pc + 2 + v.t[1]) % MEM_SIZE, arena, v.t[2]);
	if (valid_reg(v.p[1]))
	{
		v.p[1] = value_from_reg(p->reg[v.p[1]]);
		if (v.p[2] == T_REG)
			write_to_reg(p->reg[v.p[2]], v.p[1]);
		else if (v.p[2] == IND_SIZE)
			write_to_core(arena, (p->pc + (v.p[2] % IDX_MOD)) % MEM_SIZE,
					v.p[1], REG_SIZE);
		else
		{
			p->pc = (p->pc + 2 + v.p[1] + v.p[2]) % MEM_SIZE;
			return (0);
		}
		p->pc = (p->pc + 2 + v.p[1] + v.p[2]) % MEM_SIZE;
		return (0);
	}
	p->pc = (p->pc + 2 + v.p[1] + v.p[2]) % MEM_SIZE;
	return (0);
}
