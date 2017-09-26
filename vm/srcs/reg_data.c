/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:14:10 by prussell          #+#    #+#             */
/*   Updated: 2017/09/26 10:40:51 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_reg(unsigned char *reg, int value)
{
	unsigned char 	*p;
	int				i;
	char			*tmp;
	char			*t;

	if (value < 0)
	{
		tmp = ft_itoh(value);
		t = tmp;
		i = 0;
		while (i < REG_SIZE)
		{
			reg[i] = ft_htoi(tmp, 2);
			i++;
			tmp += 2;
		}
		ft_strdel(&t);
		tmp = NULL;
	}
	else
	{
		value = little_to_big_endian(value);
		i = 0;
		p = (unsigned char *)&value;
		while (i < REG_SIZE)
		{
			reg[i] = p[i];
			i++;
		}
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
