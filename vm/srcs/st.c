/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:44:07 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/21 10:25:46 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	st_arg(unsigned char *reg, t_env *env, int arg, t_process *p)
{
	env->arena[(p->pc + (arg % IDX_MOD)) % MEM_SIZE].raw = *reg;
}

void	st_reg(unsigned char *reg1, unsigned char *reg2)
{
	*reg2 = *reg1;
}
