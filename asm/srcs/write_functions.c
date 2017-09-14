/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:46:36 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/14 16:41:32 by dbarrow          ###   ########.fr       */
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
		n = ((n >> 24) & 0xff) | ((n << 8) & 0xff0000) |
			((n >> 8) & 0xff00) | ((n << 24) & 0xff000000);
		write(fd, &n, DIR_SIZE);
	}
}

void	write_indirect(char *line, int fd)
{
	int	n;

	n = ft_atoi(line);
	n = (n >> 8) | (n << 8);
	write(fd, &n, IND_SIZE);
}

//Label adresses occansionally incorrect, otherwise great :)
void    write_label_adrs(t_src_line *lines, char *line, int fd, int i)
{
	int n;
	int	y;

	y = 0;
	n = 0;
	y = get_offset(lines, line);
	printf("loop exited with %d and %d\n", y, i);
	if (y > i)
	{
		while (y > i)
		{
			n += lines[i].bytes;
			i++;
		}
		n = (n >> 8) | (n << 8);
	}
	else
	{
		while (y <= i)
		{
			n += lines[i].bytes;
			i--;
		}
		n = -n;
		n = ((n & 0xFF) << 8) | ((n >> 8) & 0xFF);
	}
	printf("label index is %d\n", n);
	write(fd, (char *)&n, IND_SIZE);
}
