/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:14:10 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 10:11:26 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_reg(unsigned char *reg, int value)
{
	unsigned char 	*p;
	int				i;
	char			*tmp;

	i = 0;
	if (value < 0)
	{
		printf("t %s\n", ft_itoh(value));
		tmp = ft_itoh(value);
		i = 0;
		printf("tmp %s\n", tmp);
		while (i < REG_SIZE)
		{
			reg[i] = ft_htoi(tmp, 2);
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
