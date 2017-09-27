/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:36:57 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/26 16:12:58 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_fork(t_process *p, t_core *arena)
{
	char param[9];

	ft_bzero(param, 9);
	ft_strncpy(arena[p->pc + 1 % MEM_SIZE].value, param + 6, 2) 
	param1 = value_from_core(arena, p->pc + 1 % MEM_SIZE, IND_SIZE);
	if 
	return (1);
}
