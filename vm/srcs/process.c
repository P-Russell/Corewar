/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 08:24:29 by prussell          #+#    #+#             */
/*   Updated: 2017/09/24 07:29:44 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// create process from env variable

/* 
** init_proc loops over champs and creates a new process for each champ
*/

int		init_proc(s_env *env)
{
}

static void		clean_reg(unsigned char **reg)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER + 1)
	{
		ft_bzero(reg[i], REG_SIZE + 1);
		i++;
	}
}

t_process		*new_proc(int champ, int pc, );
{
	t_process	*new;

	new = NULL;
	if ((new = (t_process *)malloc(sizeof(t_process))))
	{
		clean_reg(new->reg);
		write_to_reg(new->reg[0], champ);
		new->pc = pc;
		new->load_address = pc
	}
	else
		return (NULL);
		
}
void		append_proc();
void		push_proc();



