/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 07:52:56 by prussell          #+#    #+#             */
/*   Updated: 2017/09/24 07:53:58 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		value_from_core(t_core *arena, int pc, int size)
{
	int		k;
	int		j;
	char	num[9];

	ft_bzero(num, 9);
	k = 0;
	j = 0;
	while (j < size)
	{
		write_char_to_hex(arena[pc].raw, num + k);
		k += 2;
		pc = (pc + 1) % MEM_SIZE;
	}
	return (ft_htoi(num, size * 2));
}
