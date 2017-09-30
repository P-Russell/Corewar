/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 07:19:38 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 07:29:08 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cyc(unsigned char op)
{
	if (op <= 15)
	{
		return (g_op_tab[op].nb_cycles);
	}
	return (0);
}