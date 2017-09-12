/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 09:07:14 by prussell          #+#    #+#             */
/*   Updated: 2017/09/12 10:03:09 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_puthex_fd(int n, int fd, int cursor)
{
	int c;

	if (n < 0)
		n = ~n + 1;
	if (n >= 16)
		ft_puthex_fd(n / 16, fd, cursor);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	if (cursor > 0 && cursor % 4 == 0)
		ft_putchar_fd(' ', fd);
	if (cursor > 0 && cursor % 39 == 0)
		ft_putchar_fd('\n', fd);
	ft_putchar_fd(c, fd);
	cursor++;
	return (cursor);
}

void	write_magic(int fd)
{
	int magic;

	magic = COREWAR_EXEC_MAGIC;

	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	write(fd, (char *)&magic, 4);
}

void	write_name_comment(t_binary *bin)
{
	char	buf[8];

	ft_bzero(buf, 8);
	write(bin->fd, bin->header.prog_name, PROG_NAME_LENGTH);
	write(bin->fd, buf, 8);
	write(bin->fd, bin->header.comment, COMMENT_LENGTH);
	write(bin->fd, buf, 4);
}

void	write_header(t_binary *bin)
{
	write_magic(bin->fd);
	write_name_comment(bin);
//	bin->cursor = ft_puthex_fd(bin->header.magic, bin->fd, bin->cursor);
}

int		write_cor(t_src_line *lines, t_binary *bin)
{
	(void)lines;
	if (!(bin->fd = open(bin->name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
	{
		ft_putstr_fd("Could not open .cor file", 2);
		return (-1);
	}
	else
	{
		write_header(bin);
		close(bin->fd);
	}
	return (0);
}
