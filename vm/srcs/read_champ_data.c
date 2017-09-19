/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:10:49 by prussell          #+#    #+#             */
/*   Updated: 2017/09/19 11:11:27 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		check_magic(t_champ *champ)
{
	char	magic[5];
	char	hex[9];
	int		mag;

	ft_bzero(magic, 5);
	ft_bzero(hex, 9);
	if (read(champ->fd, magic, sizeof(COREWAR_EXEC_MAGIC)) < 0)
		return (-1);
	write_char_to_hex(magic[0], hex);
	write_char_to_hex(magic[1], &hex[2]);
	write_char_to_hex(magic[2], &hex[4]);
	write_char_to_hex(magic[3], &hex[6]);
	printf("%s\n", hex);
	if (mag == COREWAR_EXEC_MAGIC)
		return (0);
	return (-1);
}

static int		get_name_and_size(t_champ *champ)
{
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC)) < 0)  //possible that this lseek is not nesessary as the cursor depends on the order of calls to functions
		return (-1);
	if (read(champ->fd, champ->name, PROG_NAME_LENGTH) < 0)  //Will take some tinkering but after printing out the name
		return (-1);
}

static int		get_comment(t_champ *champ)
{
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH + sizeof(int)) < 0)
		return (-1);
	if (read(champ->fd, champ->comment, COMMENT_LENGTH) < 0)
		return (-1);
}


int		read_champ_data(t_champ *champs, int num_champs)
{
	int	i;

	i = 0;
	while (i < num_champs)
	{
		if (check_magic(champs + i) < 0 || get_name(champs + i) < 0 ||
			get_stated_size(champs + i) < 0 || get_comment(champs + i) < 0)
			return (-1);
		else if (close(champs[i].fd) < 0)
			return (-1);
		i++;
	}
}
