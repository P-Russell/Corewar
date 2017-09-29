/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:00:20 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/29 10:00:38 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	get_value(int acb, int param_num, int *pc, t_core *arena)
{
	int	ans;

	if (is_register(acb, param_num) == 1)
	{
		ans = data_var(*pc, arena, T_REG);
		*pc = (*pc + T_REG) % MEM_SIZE;
		return (ans);
	}
	else if (is_direct(acb, param_num) == 1)
	{
		ans = data_var(*pc, arena, DIR_SIZE);
		*pc = (*pc + DIR_SIZE) % MEM_SIZE;
		return (ans);
	}
	ans = data_var(((*pc + data_var(*pc, arena, IND_SIZE)) % IDX_MOD) %
			MEM_SIZE, arena, IND_SIZE);
	*pc = (*pc + IND_SIZE) % MEM_SIZE;
	return (ans);
}

static int	exec_op(t_process *p, t_core *arena, int *param, int acb)
{
	if (is_register(acb, 3) == 1 && valid_reg(arena[(p->pc + 3) %
				MEM_SIZE].raw))
	{
		param[0] = get_value(acb, 1, &(p->pc), arena);
		param[1] = get_value(acb, 2, &(p->pc), arena);
		param[2] = arena[p->pc].raw;
		p->pc = (p->pc + 1) % MEM_SIZE;
		write_to_reg(p->reg[param[2]], param[0] ^ param[1]);
	}
	else
	{
		p->pc = pc_counter(p->pc, acb, 1);
		p->pc = pc_counter(p->pc, acb, 2);
		p->pc = pc_counter(p->pc, acb, 3);
		return (0);
	}
	return (1);
}

int			op_xor(t_process *p, t_core *arena)
{
	int		i;
	int		param[3];
	int		acb;

	acb = arena[(p->pc + 1) % MEM_SIZE].raw;
	p->pc = (p->pc + 2) % MEM_SIZE;
	i = 1;
	while (i <= 2)
	{
		if ((is_register(acb, i) == 1 && valid_reg(arena[(p->pc + i - 1) %
						MEM_SIZE].raw)) || is_direct(acb, i) == 1 ||
				is_indirect(acb, i) == 1)
			i++;
		else
			break ;
	}
	p->cycles_to_exec = g_op_tab[arena[(p->pc + 3) % MEM_SIZE].raw].nb_cycles;
	if (i == 3)
		return (exec_op(p, arena, (int *)param, acb));
	return (0);
}
