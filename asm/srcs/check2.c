/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:50:47 by prussell          #+#    #+#             */
/*   Updated: 2017/09/12 13:11:00 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_code_line(char **line)
{
	while (*line)
	{
		if (is_label_address(*line) || is_opcode(*line))
			return (1);
		else if (is_comment(*line))
			return (0);
		line++;
	}
	return (0);
}

int		is_valid_fd(int fd)
{
	return (fd > 0);
}
