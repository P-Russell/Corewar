/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:01:30 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 17:43:44 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_arena(t_env env)
{
	int		i;

	i = 0;
    printf("Printing arena: %s\n", env.player_nums);
	while (i < MEM_SIZE)
	{
		ft_putstr((char *)env.arena[i].value);
		ft_putstr(" ");
		if ((i + 1) % 64 == 0)
			ft_putstr("\n");
		i++;
	}
}
