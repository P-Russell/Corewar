 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:24:03 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/22 11:00:32 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_reg(unsigned char *reg, int index, unsigned char value)
{

}

int		value_from_core(t_core *arena, int *pc, int size)
{
	char *num[sizeof(int) * 2 + 1];

	ft_bzero(num, sizeof(int) * 2 + 1);
	k = 0;
	j = 0;
	while (j < size)
	{
		write_char_to_hex(arena[*pc].raw, num + k);
		k + 2;
		*pc = (*pc + 1) % MEM_SIZE;
	}
	return (ft_htoi(num, size));
}

int		value_from_reg(unsigned char **reg, int index);
{
	//function iterrates ove REG_NUM bytes stored at reg[index]
	//and returns an int value of these bytes
	char *num[REG_SIZE * 2 + 1];

	ft_bzero(num, REG_SIZE * 2 + 1);
	k = 0;
	j = 0;
	while (reg[index][j] && j < REG_SIZE)
	{
		write_char_to_hex(reg[index][j], num + k);
		k + 2;
		j++;
	}
	return (ft_htoi(num, REG_SIZE));
}

int		add(t_process *p, t_core *arena)
{
	int	i;
	int param1;
	int param2;
	int	param3;
	int	acb;

	p->pc = (p->pc + 1) % MEM_SIZE;
	acb = (arena[pc].raw);
	p->pc = (p->pc + 1) % MEM_SIZE;
	param1 = value_from_reg(p->reg, arena[p->pc].raw);
	p->pc = (p->pc + 1) % MEM_SIZE;
	param2 = value_from_reg(p->reg, arena[p->pc].raw);
	p->pc = (p->pc + 1) % MEM_SIZE;
	param3 = value_from_reg(p->reg, arena[p->pc].raw);
	p->pc = (p->pc + 1) % MEM_SIZE;
	if (!is_reg(param1) || !is_reg(param2) || !is_reg(param3))
		return (-1);
	write_to_reg(p_reg, param3, param1 + param2);
	p->cycles_to_exec =  g_op_tab[arena[p->pc] - 1].nb_cycles;
	return (0);
}