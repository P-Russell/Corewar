/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:31:26 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 21:43:08 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		put_live(t_process *p)
{
	ft_putstr("a process shows that player ");
	ft_putnbr(p->player_num);
	ft_putchar(' ');
	ft_putstr(p->player_name);
	ft_putchar(' ');
	ft_putendl("is alive");
}

int			op_live(t_process *p, t_core *arena)
{
	printf("live\n");
	int	param;

	param = data_var((p->pc + 1) % MEM_SIZE, arena, DIR_SIZE);
	printf("param %d pc %d\n", param, (p->pc + 1));
	p->pc = (p->pc + 1 + DIR_SIZE) % MEM_SIZE;
	if (param == p->player_num)
	{
		p->live_calls++;
		put_live(p);
		return (p->player_num);
	}
	return (0);
}
