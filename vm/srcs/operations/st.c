/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:44:07 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/26 16:14:06 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int     st(t_process *p, t_core *arena)
{
    int param;
    int index;
    int acb;

    p->pc = (p->pc + 1) % MEM_SIZE;
    acb = (arena[p->pc].raw);
    p->pc = (p->pc + 1) % MEM_SIZE;
    if (is_register(acb, 1) == 1 &&
            valid_reg(arena[(p->pc + 1) % MEM_SIZE].raw))
        param = value_from_reg(p->reg[arena[(p->pc + 1) % MEM_SIZE].raw]);
    if ((is_register(acb, 2) == 1) && 
        valid_reg(arena[(p->pc + 1) % MEM_SIZE].raw))
    {
        index = arena[(p->pc + 1) % MEM_SIZE].raw + p->pc + 1;
        write_to_reg(p->reg[index], param);
    }
    return (0);
}
