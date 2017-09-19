/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:17:32 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/19 11:05:43 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "op.h"
//#include "vm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_power(int a, int b)
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

int		htoi(char *str, size_t len)
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
