/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:41:52 by prussell          #+#    #+#             */
/*   Updated: 2017/09/22 15:22:19 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
void	print_champ_data(s_env env)
{

}
*/
int		main(int argc, char **argv)
{
	t_env	env;

	if (argc == 1 || init_env(argc, argv, &env) < 0)
	{
		ft_putendl_fd(PARAM_ERROR, 2);
		return (-1);
	}
	if (read_champ_data(&env, env.num_players) < 0)
	{
		ft_putendl_fd("Read .cor error", 2);
		return (-1);
	}
	read_champs_into_core(&env);
//	print_champ_data(env);
//	print_arena(env);
	return (0);	
}
