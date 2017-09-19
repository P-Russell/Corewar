/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_to_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:31:43 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/19 12:00:02 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	load_addr_val(t_env *env)
{
	unsigned int	i;
	unsigned int	step;

	i = 0;
	step = (MEM_SIZE >> 1) / (env->num_players);
	while (i < env->num_players)
	{
		env->champs[i].load_address = step * (i + 1);
		i++;
	}
}

void	load_mem(t_env *env, int i)
{
	unsigned int	j;
	unsigned int	addr;

	j = 0;
	addr = env->champs[i].load_address;
	while (j < CHAMP_MAX_SIZE)
	{
		env->arena[addr + j].raw = env->champs[i].code[j];
		env->arena[addr + j].champ_num = env->champs[i].player_num;
		write_char_to_hex(env->arena[addr + j].raw, env->arena[addr + j].value);
		j++;
	}
}

void	read_champs_into_core(t_env *env)
{
	unsigned int	i;

	load_addr_val(env);
	i = 0;
	while (i < env->num_players)
	{
		load_mem(env, i);
		i++;
	}
}
