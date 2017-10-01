/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:41:52 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 11:34:16 by prussell         ###   ########.fr       */
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

void	print_proc_data(t_process *proc)
{
	t_process *cur;
	int			i;

	printf("---------------------------------------\n");
	cur = proc;
	while (cur)
	{
		printf("Player num: %d\n", cur->player_num);
		printf("calls to live %d\n", cur->live_calls);
		printf("player name: %s\n", cur->player_name);
		printf("cycles to exec %d\n", cur->cycles_to_exec);
		printf("carry: %d\n", cur->carry);
		printf("pc: %d\n", cur->pc);
		i = 0;
		while (i < REG_NUMBER)
			printf("%x, ", value_from_reg(cur->reg[i++]));
		printf("\n");
		i++;
		printf("---------------------------------------\n");
		cur = cur->next;
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
	if ((env.process = init_process(env.champs, env.num_players)) == NULL)
	{
		ft_putendl_fd("Process init error", 2);
		return (-1);
	}
//	print_champ_data(env.champs, env.num_players);
//	write_to_reg(env.process->reg[4], 89);
//	print_proc_data(env.process);
	t_process *cur = env.process;
	while(cur)
	{
		cur->carry = 1;
		exec_proc(cur, env.arena);
		cur = cur->next;
	}
	game_loop(&env);
//	print_proc_data(env.process);
//	printf("%d\n", check_processes(&env.process));
//	printf("call to check processes\n");
//	print_proc_data(env.process);
//	print_arena(env);
	return (0);	
}
