/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 08:40:02 by prussell          #+#    #+#             */
/*   Updated: 2017/09/20 12:02:07 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		check_player_numbers(t_env *env)
{
	unsigned int	i;
	char			possible;

	possible = '1';
	i = 0;
	while (i < env->num_players)
	{
		if (env->player_nums[i] == 0)
		{
			while (ft_strchr(env->player_nums, possible) != NULL)
				possible++;
			env->player_nums[i] = possible;
			env->champs[i].player_num = possible - '0';
		}
		else
			env->champs[i].player_num = env->player_nums[i] - '0';
		i++;
	}
	i = 0;
}

static int		new_champ(char *file_name, t_champ *champ, unsigned int play_num)
{
	printf("creating new champ from %s\n", file_name);
	if (play_num <= MAX_PLAYERS)
	{
		champ->filename = file_name;	//ptr aliasing could be prob
		if ((champ->fd = open(file_name, O_RDONLY)) < 0)
		{
			ft_putstr_fd("could not open: ", 2);
			ft_putendl_fd(file_name, 2);
			return (-1);
		}
		champ->player_num = play_num;
		ft_bzero(champ->name, PROG_NAME_LENGTH + 1);
		ft_bzero(champ->comment, COMMENT_LENGTH + 1);
		ft_bzero(champ->code, CHAMP_MAX_SIZE + 1);
		champ->size = 0;
		champ->carry = 0;
		champ->load_address = 0;
		champ->PC = 0;
		return (1);
	}
	ft_putendl_fd("player number specified exceeds MAX_PLAYERS", 2);
	return (-1);
}

/**
** ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...
**/

int		init_env_loop(int argc, char **argv, t_env *env, int i)
{
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-dump") == 0)
		{	
			if (env->dump != 0 || !argv[i + 1] || !ft_isnumber(argv[i + 1]))
				return (-1);
			env->dump = ft_atoi(argv[i + 1]);
		}
		else if (ft_strcmp(argv[i], "-n") == 0)
		{
			if ((i + 2) < argc && ft_isnumber(argv[i + 1]) && ft_strstr(argv[i + 2], ".cor") != NULL)
			{
				if (new_champ(argv[i + 2], &(env->champs[env->num_players]),
					ft_atoi(argv[i + 1])) < 0)
					return (-1);
				env->player_nums[env->num_players] = ft_atoi(argv[i + 1]) + '0';
				env->num_players++;
			}
			else
				return (-1);
			i += 2;
		}
		else if (ft_strstr(argv[i], ".cor") != NULL)
		{
			if (new_champ(argv[i], &env->champs[env->num_players], 0) < 0)
				return (-1);
			env->num_players++;
		}
		i++;
	}
	return (1);
}

int		init_env(int argc, char **argv, t_env *env)
{
	int i;

	i = 1;
	if (!is_valid_params(argv))
		return (-1);
	env->dump = 0;
	env->num_players = 0;
	ft_bzero(env->player_nums, MAX_PLAYERS);
	if (init_env_loop(argc, argv, env, i) < 0)
		return (-1);
	check_player_numbers(env);
/*	unsigned int j = 0;
	("Used Numbers: %s\n", env->player_nums);
	while (j < env->num_players)
	{
		("%d\n", env->champs[j].player_num);
		j++;
	}*/
	init_arena(env);
	return (1);
}
