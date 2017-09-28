/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:51:06 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/28 08:12:46 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm/includes/vm.h"

int         first_val(t_process *p, t_core *arena)
{
    int     val;
    int     acb;

    p->pc = (p->pc + 1) % MEM_SIZE;
    acb = (arena[p->pc].raw);
    p->pc = (p->pc + 1) % MEM_SIZE;
    if (is_register(acb, 1) == 1 && valid_reg(arena[(p->pc + 1) % MEM_SIZE].raw))
        val = value_form_core(arena, p->pc, T_REG);
    if (is_direct(acb, 1) == 1)
        val = value_from_core(arena, p->pc, T_DIR);
    if (is_indirect(acb, 1) == 1)
        val = value_from_core(arena, (p->pc + value_from_reg(p->reg[arena[p->pc].raw]) % IDX_MOD), T_IND);
    return (val);
}

int     second_val(t_process *p, t_core *arena)
{
    int     val;
    int     acb;

    p->pc = (p->pc + 1) % MEM_SIZE;
    acb = (arena[p->pc].raw);
    p->pc = (p->pc + 1) % MEM_SIZE;
    if (is_direct(acb, 2) == 1)
        val = value_from_core(arena, p->pc, T_DIR);
    if (is_register(acb, 2) == 1 && valid_reg(arena[(p->pc) % MEM_SIZE].raw))
        val = value_from_core(arena, p->pc, T_REG);
    return (val);
}

void		ldi(t_process *p, t_core *arena)
{
    int     val1;
    int     val2;
    int     acb;
    int     res;
    int     index;

    p->pc = (p->pc + 1) % MEM_SIZE;
    acb = arena[p->pc].raw;
    val1 = first_val(process, arena);
    val2 = second_val(process, arena);
    res = val1 + val2;
    res = value_from_core(arena, p->pc + (res % IDX_MOD), REG_SIZE);
    index = 
    if (is_register(acb, 3) == 1 && valid_reg(arena[(p->pc + 1) % MEM_SIZE].raw))
    {
        write_to_reg(p->reg[index], res);
        p->carry = (res) ? 0 : 1;
    }
}
