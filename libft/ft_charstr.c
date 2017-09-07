/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:05:41 by prussell          #+#    #+#             */
/*   Updated: 2017/09/06 15:23:46 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charstr(const char *big, const char c)
{
	int i;

	if (c == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		if (big[i] == c)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
