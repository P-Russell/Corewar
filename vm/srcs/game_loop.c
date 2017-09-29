/* ************************************************************************** *//*                                                                            *//*                                                        :::      ::::::::   *//*   game_loop.c                                        :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     *//*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        *//*                                                +#+#+#+#+#+   +#+           *//*   Created: 2017/09/20 08:37:24 by prussell          #+#    #+#             *//*   Updated: 2017/09/29 10:18:12 by lde-jage         ###   ########.fr       *//*                                                                            *//* ************************************************************************** */#include "vm.h"int		exec_proc(t_process *p, t_core *arena){	int	ret;	int	op;	if (p->cycles_to_exec > 1)	{		p->cycles_to_exec--;		return (0);	}	else if (p->cycles_to_exec == 1)	{		op = arena[p->pc].raw - 1;		if (arena[p->pc].raw < 16 && arena[p->pc].raw >= 0)			ret = g_op_ptr[arena[p->pc].raw - 1](p, arena);		else		{			p->pc = (p->pc + 1) % MEM_SIZE;			return (0);		}		if (op == 0 && ret)			return (p->player_num);	}	return (0);}/*** Check_processes removes processes that have not made a valid call to live op** since last check. Also returns NBR_LIVE if one process has made NBR_LIVE** calls to live op.*/int				check_processes(t_process **head){	t_process	*cur;	t_process	*tmp;	int			ret;	ret = 0;	while (*head && (*head)->live_calls == 0)		del_first_proc(head);	cur = *head;	if (cur && cur->live_calls >= NBR_LIVE)		ret = NBR_LIVE;	while (cur && cur->next)	{		if (cur->next->live_calls >= NBR_LIVE)			ret = NBR_LIVE;		if (cur->next->live_calls == 0)		{			tmp = cur->next;			cur->next = tmp->next;			free(tmp);		}		cur = cur->next;	}	return (ret);}/*** run_processes returns the playet num of the last process to call live*/static int		run_processes(t_env *e, int iter){	t_process	*p;	int			player;	player = 0;	while(iter)	{		p = e->process;		while(p)		{//			player = exec_proc(p, e->arena);			p = p->next;		}		iter--;	}	return (player);}int				game_loop(t_env *env){	int		c_to_die;	int		i;	int		checks;	int		last_alive;	c_to_die = CYCLE_TO_DIE;	i = 0;	checks = 1;	while (env->process)	{		i += (c_to_die / MAX_CHECKS);		last_alive = run_processes(env, c_to_die / MAX_CHECKS);		checks++;		if (check_processes(&env->process) == NBR_LIVE)			c_to_die -= CYCLE_DELTA;		if (checks == MAX_CHECKS)		{			checks = 1;			i = 0;			c_to_die -= CYCLE_DELTA;		}	}//	winner(env->champs, last_alive);	return (0);}