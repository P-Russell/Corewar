/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:57:36 by prussell          #+#    #+#             */
/*   Updated: 2017/09/20 08:41:21 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		clean_arena(t_core *arena)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_bzero (arena->value, 3);
		arena->value[0] = '0';
		arena->value[1] = '0';
		arena->champ_num = 0;
		i++;
	}
}

void			init_arena(t_env *env)
{
	clean_arena(env->arena);
}
