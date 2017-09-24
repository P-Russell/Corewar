/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 09:50:00 by prussell          #+#    #+#             */
/*   Updated: 2017/09/24 10:37:22 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	*init_process(t_champ *champs, int num_champs)
{
	int			i;
	int			j;
	t_process 	*new;
	t_process	*head;

	j = 1;
	head = NULL;
	while (j <= MAX_PLAYERS)
	{
		i = 0;
		while (i < num_champs)
		{
			if (champs[i].player_num == j)
			{
				if ((new = new_proc_from_champ(champs + i)) == NULL)
					return (NULL);
				push_proc(&head, new);
			}
			i++;
		}
		j++;
	}
	return (head);
}
