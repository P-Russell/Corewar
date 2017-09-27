/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:05:20 by prussell          #+#    #+#             */
/*   Updated: 2017/09/27 15:41:09 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_var(t_op_var *v)
{
	int	i;

	i = 0;
	ft_bzero(v->param, MAX_ARGS_NUMBER);
	ft_bzero(v->types, MAX_ARGS_NUMBER);
	while (i < MAX_ARGS_NUMBER)
	{
		if (is_register(v->acb, i + 1))
			v->types[i] = T_REG;
		else if (is_direct(v->acb, i + 1))
			v->types[i] = T_DIR;
		else if (is_indirect(v->acb, i + 1))
			v->types[i] = T_IND;
		i++;
	}
}
