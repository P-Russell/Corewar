/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:05:20 by prussell          #+#    #+#             */
/*   Updated: 2017/09/29 10:15:38 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_var(t_op_var *v)
{
	int	i;

	i = 0;
	ft_bzero(v->p, MAX_ARGS_NUMBER);
	ft_bzero(v->t, MAX_ARGS_NUMBER);
	while (i < MAX_ARGS_NUMBER)
	{
		if (is_register(v->acb, i))
			v->t[i] = T_REG;
		else if (is_direct(v->acb, i))
			v->t[i] = T_DIR;
		else if (is_indirect(v->acb, i))
			v->t[i] = T_IND;
		i++;
	}
}
