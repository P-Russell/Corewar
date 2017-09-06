/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:49:02 by prussell          #+#    #+#             */
/*   Updated: 2017/09/06 15:28:53 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_valid_fd(int fd)
{
	return (fd > 0);
}

int		is_opcode(char *line)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(line, op_tab[i].name) == 0)
			return (op_tab[i].opcode);
	}
	return (0);
}

int		is_label(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_charstr(LABEL_CHARS, line[i] == NULL)
				break ;
		i++;
	}
	if (line[i] == LABEL_CHAR && i > 0)
		return (1);
	return (0);
}

int		is_param(char *line)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (line[i])
	{
		if (line[i] == DIRECT_CHAR)
			ret = DIR_CODE;
		else if (line[i] == 

	}
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
