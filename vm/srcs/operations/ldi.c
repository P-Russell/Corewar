/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:51:06 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/21 12:01:52 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ldi(int addr, int val, unsigned char *reg, t_env *env, t_process *p)
{
	*reg = env->arena[(p->pc + (addr % IDX_MOD)) % MEM_SIZE].raw + val;
	p->carry += 1;
}
