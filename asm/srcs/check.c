/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:49:02 by prussell          #+#    #+#             */
/*   Updated: 2017/08/30 09:08:02 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

int		is_valid_source(int	fd)
{
	return (fd > 0);
}

int		is_comment(char *line)
{
	int i;

	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == COMMENT_CHAR)
		return (1);
	return (0);
}
