/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:41:52 by prussell          #+#    #+#             */
/*   Updated: 2017/09/19 16:01:06 by prussell         ###   ########.fr       */
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
	if (read_champ_data(env.champs, env.num_players) < 0)
	{
		ft_putendl_fd("Read .cor error", 2);
		return (-1);
	}
	read_champs_into_core(&env);
	print_arena(env);
	return (0);	
}
