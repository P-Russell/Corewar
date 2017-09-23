/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:14:10 by prussell          #+#    #+#             */
/*   Updated: 2017/09/23 12:16:51 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_reg(unsigned char *reg, int value)
{
	int				tmp;
	unsigned char 	*p;
	int				i;

	value = little_to_big_endian(value);
	p = (unsigned char *)&value;
	while (i < REG_SIZE)
	{
		reg[i] = p[i];
		i++;
	}
}

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

int		value_from_reg(unsigned char **reg, int index)
{
	int		k;
	int		j;
	char 	num[REG_SIZE * 2 + 1];

	ft_bzero(num, REG_SIZE * 2 + 1);
	k = 0;
	j = 0;
	while (reg[index][j] && j < REG_SIZE)
	{
		write_char_to_hex(reg[index][j], num + k);
		k += 2;
		j++;
	}
	return (ft_htoi(num, REG_SIZE * 2 + 1));
}
