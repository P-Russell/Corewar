/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:15:27 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 01:04:51 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		exec_proc(t_process *p, t_core *arena)
{
	int	ret;
	int	op;

	ret = 0;
	if (p->cycles_to_exec > 1)
	{
		p->cycles_to_exec--;
		return (0);
	}
	else if (p->cycles_to_exec <= 1)
	{
		op = arena[p->pc].raw - 1;
		if (op < 16 && op >= 0)
		{
			ret = g_op_ptr[op](p, arena);
			p->cycles_to_exec = cyc(arena[p->pc].raw);
		}
		else
		{
			p->pc = (p->pc + 1) % MEM_SIZE;
			return (0);
		}
		if (op == 0 && ret)
			return (ret);
	}
	return (0);
}

int		run_processes(t_env *e, int iter)
{
	t_process	*p;
	int			player;

	player = 0;
	while(iter > 0)
	{
		p = e->process;
		while(p != NULL)
		{
			player = exec_proc(p, e->arena);
			p = p->next;
		}
		iter--;
	}
	return (player);
}

int		run_processes_dump(t_env *e, int iter)
{
	t_process			*p;
	int					player;
	static unsigned int	cycles;

	cycles = 0;
	player = 0;
	while(iter > 0 && cycles < e->dump)
	{
		p = e->process;
		while(p != NULL)
		{
			player = exec_proc(p, e->arena);
			p = p->next;
		}
		cycles++;
		iter--;
	}
	if (cycles == e->dump)
		exit_prog(e);
	return (player);
}
