/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:14:10 by prussell          #+#    #+#             */
/*   Updated: 2017/09/25 13:38:01 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Function write to reg is not working properly.
**
*/

void	write_to_reg(unsigned char *reg, int value)
{
	unsigned char 	*p;
	int				i;

	if (value < 0)
	{
		value = ~value;
		value++;
	}
	p = (unsigned char *)&value;
	i = 0;
	value = little_to_big_endian(value);
	while (i < REG_SIZE)
	{
		reg[i] = p[i];
		i++;
	}
}

int		value_from_reg(unsigned char *reg)
{
	int		k;
	int		j;
	char 	num[REG_SIZE * 2 + 1];

	ft_bzero(num, REG_SIZE * 2 + 1);
	k = 0;
	j = 0;
	while (j < REG_SIZE)
	{
		write_char_to_hex(reg[j], num + k);
		k += 2;
		j++;
	}
	return (ft_htoi(num, REG_SIZE * 2));
}
