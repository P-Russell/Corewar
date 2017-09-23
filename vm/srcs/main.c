/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:41:52 by prussell          #+#    #+#             */
/*   Updated: 2017/09/23 09:50:55 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_champ_data(t_champ *champs, int num_players)
{
	int	i;

	i = 0;
	printf("--------------------------\n");
	while (i < num_players)
	{
		printf("index i: %d\n", i);
		printf("filename: %s\n", champs[i].filename);
		printf("player_num: %d\n", champs[i].player_num);
		printf("name: %s\n", champs[i].name);
		printf("comment: %s\n", champs[i].comment);
		printf("size: %d\n", champs[i].size);
		printf("stated size: %d\n", champs[i].stated_size);
		printf("load_address: %d\n", champs[i].load_address);
		printf("---------------------------\n");
		i++;
	}
}

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
	print_champ_data(env.champs, env.num_players);
	print_arena(env);
	return (0);	
}
