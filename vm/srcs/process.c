/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 08:24:29 by prussell          #+#    #+#             */
/*   Updated: 2017/09/24 10:23:18 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		clean_reg(unsigned char reg[REG_NUMBER + 1][REG_SIZE + 1])
{
	int	i;

	i = 0;
	while (i < REG_NUMBER + 1)
		ft_bzero(reg[i++], REG_SIZE + 1); 
}

t_process		*new_proc_from_champ(t_champ *champ)
{
	t_process	*new;

	if ((new = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	new->pc = champ->pc;
	new->load_address = champ->pc;
	new->player_num = champ->player_num;
	new->carry = 0;
	new->alive = 1;
	new->cycles_to_die = CYCLE_TO_DIE;;
	clean_reg(new->reg);
	new->next = NULL;
	return (new);
}

static void		cpy_reg(unsigned char src[REG_NUMBER + 1][REG_SIZE + 1],
		unsigned char dst[REG_NUMBER + 1][REG_SIZE + 1])
{
	int	i;
	int	j;

	i = 0;
	while (i < REG_NUMBER + 1)
	{
		j = 0;
		while (j < REG_SIZE + 1)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

t_process		*new_proc(t_process *father, int pc)
{
	t_process	*new;

	new = NULL;
	if ((new = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	new->pc = pc;
	new->load_address = pc;
	new->player_num = father->player_num;
	new->carry = father->carry;
	new->alive = 1;
	new->cycles_to_die = father->cycles_to_die;
	cpy_reg(father->reg, new->reg);
	new->next = NULL;
	return (new);
}

void		push_proc(t_process **head, t_process *p)
{
	p->next = *head;
	*head = p;
}

void		append_proc(t_process *head, t_process *new)
{
	t_process *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
