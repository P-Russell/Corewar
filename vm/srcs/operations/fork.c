/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:36:57 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/22 08:49:39 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fork(int addr, t_process *p, t_env *env, unsigned int i, t_process *r)
{
	unsigned int	j;

	j = 0;
	while (j < env->champs[i].size)
	{
		env->arena[(p->pc + j + (addr % IDX_MOD)) % MEM_SIZE].raw =
			env->champs[i].code[j];
		j++;
	}
	r->load_address = (p->pc + (addr % IDX_MOD)) % MEM_SIZE;
	r->cycles_to_exec = ;
	r->pc = r->load_address;
	r->core_ptr = &env->arena[r->load_address];
	r->carry = ;
	r->alive = 1;
	r->cycles_to_die;
}
