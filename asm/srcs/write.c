/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 09:07:14 by prussell          #+#    #+#             */
/*   Updated: 2017/09/09 12:56:20 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_bin_var(t_binary *bin, fd)
{
	if (!(bin->name = get_name()))
		ft_putstr_fd("Could not open .cor file", 2);
	if (!(bin->comment = get_comment()))
		ft_putstr_fd("Could not open .cor file", 2);
	bin->cursor = 0;
	if (!(bin->fd = open(file->name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
		ft_putstr_fd("Could not open .cor file", 2);

}

int		write_cor(t_src_line lines, t_binary bin, int fd)
{
	if (!(file->fd = open(file->name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
		ft_putstr_fd("Could not open .cor file", 2);
	write_magic(file);
	return (0);
}


