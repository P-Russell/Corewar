/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:21:17 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 09:53:48 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		valid_param(char *param)
{
	return (ft_strstr(param, "-dump") != NULL ||
				ft_strstr(param, "-n") != NULL ||
				ft_strstr(param, ".cor") != NULL ||
				ft_isnumber(param));
}

int		is_valid_params(char **params)
{
	int	i;

	i = 1;
	while (params[i])
	{
		if (ft_strstr(params[i], "-dump") != NULL)
		{
			if (params[i + 1] && !ft_isnumber(params[i + 1]))
				return (0);
		}
		else if (ft_strstr(params[i], "-n") != NULL)
		{
			if (params[i + 1] && !ft_isnumber(params[i + 1]))
				return (0);
			else if (params[i + 2] && ft_strstr(params[i + 2], ".cor") == NULL)
				return (0);
		}
		else if (!valid_param(params[i]))
			return (0);
		i++;
	}
	return (1);
}
