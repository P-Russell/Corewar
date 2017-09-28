/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:03:10 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/28 10:03:22 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		pc_counter(int pc, int acb, int param_num)
{
	if (is_direct(acb, param_num) == 1)
		return ((pc + T_DIR) % MEM_SIZE);
	else if (is_indirect(acb, param_num) == 1)
		return ((pc + T_IND) % MEM_SIZE);
	return ((pc + T_REG) % MEM_SIZE);
}
