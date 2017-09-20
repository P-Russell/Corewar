/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:41:52 by prussell          #+#    #+#             */
/*   Updated: 2017/09/20 15:37:41 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc == 1 || init_env(argc, argv, &env) < 0)
	{
		ft_putendl_fd(PARAM_ERROR, 2);
		return (-1);
	}
    printf("init_env done\n");
	if (read_champ_data(&env, env.num_players) < 0)
	{
		ft_putendl_fd("Read .cor error", 2);
		return (-1);
	}
    printf("read champs done\n");
    printf("champ name: %s\n", env.champs[1].name);
	read_champs_into_core(&env);
	printf("champs in core\n");
	print_arena(env);
	return (0);	
}
