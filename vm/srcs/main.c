/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:41:52 by prussell          #+#    #+#             */
/*   Updated: 2017/09/19 11:48:04 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (init_env(argc, argv, &env) < 0 || argc == 1)
	{
		ft_putendl_fd(PARAM_ERROR, 2);
		return (-1);
	}
	/*
	if (read_champ_data(&(env.champs), env.num_players) < 0)
	{
		ft_putendl_fd("Read .cor error", 2);
		return (-1);
	}*/
//	if (read_champs_into_core(&env) < 0)
		/* Function sets variable at champ to load address (MEM_SIZE / env->num_players * 2)
		 * reads champ->code in to env->arena[champ->load_address]
		 * bonus - debug file - print_arena in accordance with pdf
		 */
	return (0);	
}
