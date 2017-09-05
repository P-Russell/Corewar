/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:49:02 by prussell          #+#    #+#             */
/*   Updated: 2017/09/05 09:53:30 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

int		is_valid_fd(int fd)
{
	return (fd > 0);
}

int		is_opcode(char *line)
{
	if (ft_strcmp(line, "live") == 0)
		return (1);
	else if (ft_strcmp(line, "ld") == 0)
		return (2);
	else if (ft_strcmp(line, "st") == 0)
		return (3);
	else if (ft_strcmp(line, "add") == 0)
		return (4);
	else if (ft_strcmp(line, "sub") == 0)
		return (5);
	else if (ft_strcmp(line, "and") == 0)
		return (6);
	else if (ft_strcmp(line, "or") == 0)
		return (7);
	else if (ft_strcmp(line, "xor") == 0)
		return (8);
	else if (ft_strcmp(line, "zjmp") == 0)
		return (9);
	else if (ft_strcmp(line, "ldi") == 0)
		return (10);
	else if (ft_strcmp(line, "sti") == 0)
		return (11);
	else if (ft_strcmp(line, "fork") == 0)
		return (12);
	else if (ft_strcmp(line, "lld") == 0)
		return (13);
	else if (ft_strcmp(line, "lldi") == 0)
		return (14);
	else if (ft_strcmp(line, "lfork") == 0)
		return (15);
	else if (ft_strcmp(line, "aff") == 0)
		return (16);
	else if (ft_strcmp(line, "ld") == 0)
		return (17);
	return (0);
}

int		is_label(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR && i > 0)
			return (1);
		i++;
	}
	return (0);
}

int		is_comment(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == COMMENT_CHAR)
		return (1);
	return (0);
}
