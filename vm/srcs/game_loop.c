/* ************************************************************************** *//*                                                                            *//*                                                        :::      ::::::::   *//*   game_loop.c                                        :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     *//*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        *//*                                                +#+#+#+#+#+   +#+           *//*   Created: 2017/09/20 08:37:24 by prussell          #+#    #+#             *//*   Updated: 2017/10/01 02:12:52 by lde-jage         ###   ########.fr       *//*                                                                            *//* ************************************************************************** */#include "vm.h"static	void	winner(t_env *env, int player_num){	printf("player num %d\n", player_num);	unsigned int	i;	i = 0;	while (i < env->num_players)	{		if (env->champs[i].player_num == player_num)		{			ft_putstr("Player ");			ft_putnbr(env->champs[i].player_num);			ft_putchar(' ');			ft_putstr(env->champs[i].name);			ft_putendl(" won");			exit_prog(env);		}		i++;	}	ft_putendl_fd("could not find player num", 2);}/*** Check_processes removes processes that have not made a valid call to live op** since last check. Also returns NBR_LIVE if one process has made NBR_LIVE** calls to live op.*/int				check_processes(t_process **head){	t_process	*cur;	t_process	*tmp;	int			ret;	static int	i = 0;	ret = 0;	while (*head && (*head)->live_calls == 0)	{		printf("del %d\n", i);		i++;		del_first_proc(head);	}	cur = *head;	if (cur && cur->live_calls >= NBR_LIVE)	{		ret = NBR_LIVE;		cur->live_calls = 0;	}	while (cur && cur->next)	{		if (cur->next->live_calls >= NBR_LIVE)		{			ret = NBR_LIVE;			cur->next->live_calls = 0;			cur = cur->next;		}		else if (cur->next->live_calls <= 0)		{			printf("del %d\n", i);			i++;			tmp = cur->next;			cur->next = tmp->next;			free(tmp);			tmp = NULL;		}		else		{			cur->next->live_calls = 0;			cur = cur->next;		}	}	if (*head)		(*head)->live_calls = 0;	return (ret);}/*** run_processes returns the player num of the last process to call live*/int				game_loop(t_env *env){	int		c_to_die;	int		i;	int		checks;	int		last_alive;	int		t;	c_to_die = CYCLE_TO_DIE;	i = 0;	checks = 1;	last_alive = 1;	while (env->process)	{		printf("-----------cyc to die: %d\n", c_to_die);		i = c_to_die;		if (env->dump)			last_alive = ((t = run_processes_dump(env, i / MAX_CHECKS))) == 0 ?					last_alive : t;		else			last_alive = ((t = run_processes(env, i / MAX_CHECKS))) == 0 ?					last_alive : t;		checks++;		if (env->process && check_processes(&env->process) == NBR_LIVE)			c_to_die -= CYCLE_DELTA;		if (checks == MAX_CHECKS)		{			checks = 1;			c_to_die -= CYCLE_DELTA;		}	}	winner(env, last_alive);	return (0);}