/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:32:45 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 12:32:46 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		clean_arena(t_core *arena)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_bzero(arena[i].value, 3);
		arena[i].value[0] = '0';
		arena[i].value[1] = '0';
		arena[i].champ_num = 0;
		arena[i].raw = 0;
		i++;
	}
}

void			init_arena(t_env *env)
{
	clean_arena(env->arena);
}
