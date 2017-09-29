/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 07:52:56 by prussell          #+#    #+#             */
/*   Updated: 2017/09/29 10:13:36 by lde-jage         ###   ########.fr       */
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

int		write_to_core(t_core *arena, int pc, int value, int size)
{
	unsigned char 	*p;
	int				i;
	char			*tmp;

	if (value < 0)
	{
		tmp = ft_itoh(value);
		i = 0;
		while (i < size)
		{
			arena[pc].raw = ft_htoi(tmp, 2);
			write_char_to_hex(arena[pc].raw, arena[pc].value);
			pc = (pc + 1) % MEM_SIZE;
			i++;
			tmp += 2;
		}
	}
	else
	{
		value = little_to_big_endian(value);
		i = 0;
		p = (unsigned char *)&value;
		while (i < REG_SIZE)
		{
			arena[pc].raw = p[i];
			write_char_to_hex(p[i], arena[pc].value);
			pc = (pc + 1) % MEM_SIZE;
			i++;
		}
	}
	return (1);
}
