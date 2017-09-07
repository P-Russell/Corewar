/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:49:02 by prussell          #+#    #+#             */
/*   Updated: 2017/09/07 15:05:29 by prussell         ###   ########.fr       */
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
		if (ft_strcmp(line, g_op_tab[i].name) == 0)
			return (g_op_tab[i].opcode);
		i++;
	}
	return (0);
}

int		is_label_address(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_charstr(LABEL_CHARS, line[i]) == NULL && line[i] != LABEL_CHAR)
			return (0);
		i++;
	}
	if (line[i - 1] == LABEL_CHAR && i > 0)
		return (1);
	return (0);
}

int		is_label_param(char *line)
{
	int	i;

	i = 0;
	if (ft_charstr(line, LABEL_CHAR) == NULL)
		return (0);
	if (line[i] = DIRECT_CHAR || line [i] == 'r')
		i++;
	while (line[i])
	{
		if (ft_charstr(LABEL_CHARS, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

int		is_param(char *line)
{
	int ret;

	ret = 0;
	if (is_label_param(line))
		return (1);
	while (*line)
	{
		else if (*line != DIRECT_CHAR || *line != 'r' || *line != LABEL_CHAR)
		else if (*line == 'r')
			ret = 1;
		else if (ft_number(line))
			return (1);
		else if (ret && ft_isdigits(++line))
			return (ret);
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
