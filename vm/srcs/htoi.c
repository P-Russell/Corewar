/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:17:32 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/22 14:33:30 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		ft_power(int a, int b)
{
	int	i;
	int	t;

	i = 0;
	t = 1;
	while (i < b)
	{
		t *= a;
		i++;
	}
	return (t);
}

int			ft_htoi(char *str, size_t len)
{
	int		i;
	int		tot;
	int		power;
	int		cur;

	i = (int)len - 1;
	tot = 0;
	power = 0;
	while (i >= 0)
	{
		cur = str[i];
		if (cur <= 57)
			cur -= 48;
		else
			cur -= 55;
		tot += cur * ft_power(16, power);
		i--;
		power++;
	}
	return (tot);
}
