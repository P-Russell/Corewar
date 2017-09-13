/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:46:36 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/13 14:14:17 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    write_opcode_and_acb(t_src_line line, int fd)
{
	write(fd, &line.opcode, 1);
	if (line.acb != 0)
		write(fd, &line.acb, 1);
}

void	write_register(char *line, int fd)
{
	int	n;

	n = ft_atoi(line + 1);
	write(fd, &n, 1);
}

void	write_direct(t_src_line line, int fd, int p)
{
	int idx;
	int n;

	idx = check_idx(line.opcode);
	n = ft_atoi(line.params[p] + 1);
	if (idx == 1)
	{
		n = (n >> 8) | (n << 8);
		write(fd, &n, IND_SIZE);
	}
	else
	{
		reverse_bytes(&n, DIR_SIZE);
		write(fd, &n, DIR_SIZE);
	}
}

void	write_indirect(char *line, int fd)
{
	int	n;

	n = ft_atoi(line);
	write(fd, &n, IND_SIZE);
}

void    write_label_adrs(char *line, int fd)
{
	int n;

	line = line + 1;
	n = 43981;
	n = (n >> 8) | (n << 8);
	write(fd, (char *)&n, IND_SIZE);
}
