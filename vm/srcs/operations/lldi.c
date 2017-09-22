/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:02:35 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/21 13:28:17 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lldi(int addr, int val, unsigned char *reg, t_env *env, t_process *p)
{
	*reg = env->arena[(p->pc + addr) % MEM_SIZE].raw + val;
	p->carry += 1;
}
