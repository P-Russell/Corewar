/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_to_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:31:43 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/20 12:17:37 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		load_addr_val(t_env *env)
{
	unsigned int	i;
	unsigned int	step;

	i = 0;
	step = (MEM_SIZE >> 1) / (env->num_players);
	while (i < env->num_players)
	{
        printf("champ name: %s\n", env->champs[i].name);
		env->champs[i].load_address =  step * i;
        printf("load add for %s: %d\n", env->champs[i].name, env->champs[i].load_address);
        i++;
	}
    
}

static void		load_mem(t_env *env, int i)
{
	unsigned int	j;
	unsigned int	addr;

    printf("entered load_mem for champ %d\n", env->champs[i].player_num);
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

void		read_champs_into_core(t_env *env)
{
	unsigned int	i;

    printf("Reading champs into core %s\n", env->champs[0].name);
	load_addr_val(env);
	i = 0;
	while (i < env->num_players)
	{
        printf("Loaded player %d\n", i);
        load_mem(env, i);       
		i++;
	}
}
