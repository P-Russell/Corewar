/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:01:30 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/20 13:15:23 by tbarlow-         ###   ########.fr       */
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
		if ((i + 1) % 32 == 0)
			ft_putstr("\n");
		i++;
	}
}
