/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:50:17 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/22 08:51:09 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lfork(int addr, t_process *p, t_env *env, unsigned int i, t_process *r)
{
	unsigned int	j;

	j = 0;
	while (j < env->champs[i].size)
	{
		env->arena[(p->pc + j + addr) % MEM_SIZE].raw =
			env->champs[i].code[j];
		j++;
	}
	p->carry += 1;
	r->load_address = (p->pc + addr) % MEM_SIZE;
	r->cycles_to_exec = ;
	r->pc = r->load_address;
	r->core_ptr = &env->arena[r->load_address];
	r->carry = ;
	r->alive = 1;
	r->cycles_to_die;
}
