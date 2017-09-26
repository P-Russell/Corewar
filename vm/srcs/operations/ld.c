/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:26:01 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/26 15:27:23 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int 	ld(t_process *p, t_core *arena)
{
    int load_val;
    int param[2];
    int acb;

    p->pc = (p->pc + 1) % MEM_SIZE;
    acb = (arena[p->pc].raw);
    p->pc = (p->pc + 1) % MEM_SIZE;
    if (is_direct(acb, 0) == 1)
        load_val = value_from_core(arena, p->pc, T_DIR);      //Change to new function get index from core
    else if (is_indirect(acb, 1) == 1)
        load_val = value_from_core(arena, (p->pc + value_from_reg(p->reg[arena[p->pc].raw]) % IDX_MOD), T_IND);
    if (is_register(acb, 2) && valid_reg(arena[(p->pc + 1) % MEM_SIZE].raw))
        write_to_reg(p->reg[param[1]], load_val);
    p->pc = (p->pc + 2) % MEM_SIZE;
    p->carry = (load_val) ? 0 : 1;
    return (0);
}
