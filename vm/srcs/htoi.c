/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:17:32 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/26 15:38:54 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "vm.h"
#include <unistd.h>
int			ft_power(int a, int b)
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
/*
char	*ft_itoh(int val)
{
	char	a[9];
	char	*ans;
	int		t;
	char	hex[16];

	ans = a;
	val = ~val;
	ft_strcpy(hex, "0123456789ABCDEF");
	t = 7;
	ans[8] = '\0';
	while ((val >> 4) != 0 && t > 0)
	{
		ans[t] = hex[15 - val % 16];
		val = val >> 4;
		t--;
	}
	ans[t] = hex[15 - val % 16];
	while (t - 1 >= 0)
	{
		ans[t - 1] = 'F';
		t--;
	}
	return (ans);
}
*/
#include <stdio.h>
int		main(void)
{
	printf("%d\n",ft_htoi("FFFFFFFB", 8));
	return (0);
}
