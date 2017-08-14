/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:21:50 by prussell          #+#    #+#             */
/*   Updated: 2017/06/06 07:04:12 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		size_t		count_num(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

static		int			check_size(const char *s, int is_neg)
{
	char	*max;
	char	*min;
	size_t	s_len;

	max = ft_strdup("2147483647");
	min = ft_strdup("2147483648");
	s_len = count_num(s);
	if ((s_len > ft_strlen(max)) && is_neg == 1)
		return (0);
	else if ((s_len > ft_strlen(min)) && is_neg == -1)
		return (-1);
	return (1);
}

static		int			min_int(const char *s)
{
	char	*min;
	int		i;

	min = ft_strdup("2147483648\0");
	i = 0;
	while (min[i] != '\0')
	{
		if (min[i] != s[i])
			return (0);
		i++;
	}
	return (1);
}

int						ft_atoi(const char *s)
{
	int i;
	int sol;
	int neg;

	i = 0;
	sol = 0;
	neg = 1;
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == '\v' || s[i] == '+'
			|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ') && s[i] != '\0')
		i++;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (neg && min_int(s + i))
		return (-2147483648);
	if (check_size(s + i, neg) == 1)
		while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
			sol = sol * 10 + (s[i++] - '0');
	else if (check_size(s + i, neg) == 0)
		return (-1);
	else if (check_size(s + i, neg) == -1)
		return (0);
	return (sol * neg);
}
