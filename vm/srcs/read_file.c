/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:30:58 by prussell          #+#    #+#             */
/*   Updated: 2017/09/13 14:08:14 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		seek_to_magic(int fd)
{
	while (get_next_line(fd, line))
}

int		read_file(char *filename, t_champ *champ)
{
	int	fd;

	if (!(fd = open(filename, O_RDONLY)))
		return (EXIT_FAILURE);
	if (!seek_to_magic(fd))
		return (EXIT_FAILURE);

}
