/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:39:56 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 21:32:27 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_processes(t_process *p)
{
	t_process *cur;
	t_process *tmp;

	cur = p;
	while (cur)
	{
		tmp = cur;
		cur = tmp->next;
		free(tmp);
	}
}

void		exit_prog(t_env *env)
{
	print_proc_data(env->process);
	print_arena(*env);
	free_processes(env->process);
	exit(0);
}
