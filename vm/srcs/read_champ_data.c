/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:10:49 by prussell          #+#    #+#             */
/*   Updated: 2017/09/20 13:13:06 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	swap_two_octets(int nb)
{
	int		tmp;

	tmp = nb & 0xff;
	nb = (nb & 0xff00) / 0xff;
	nb = nb + (tmp * 0x100);
	return (nb);
}

int			little_to_big_endian(int nb)
{
	int		tmp;

	tmp = nb & 0xffff;
	nb = (nb & 0xffff0000) / 0xffff;
	tmp = swap_two_octets(tmp) * 0x10000;
	nb = swap_two_octets(nb) + tmp;
    return (nb);
}

static int		check_magic(t_champ *champ)
{
	int		magic;

	magic = 0;
	if (read(champ->fd, &magic, sizeof(COREWAR_EXEC_MAGIC)) == -1)
		return (-1);
	magic = little_to_big_endian(magic);
	//printf("magic:%d == %d\n", magic, COREWAR_EXEC_MAGIC);
	if (magic == COREWAR_EXEC_MAGIC)
		return (0);
	return (-1);
}

static int		get_name_and_size(t_champ *champ)
{
	int		i;
	char	buf;

	i = 0;
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC), SEEK_SET) < 0)
		return (-1);
	while (read(champ->fd, &buf, 1) > 0 && i < PROG_NAME_LENGTH) 
		champ->name[i++] = buf;
	printf("champ->name: '%s'\n", champ->name);
	return (0);
}

static int		get_comment(t_champ *champ)
{
	int		i;
	char 	buf;

	i = 0;
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH
	+ sizeof(int) + 4, SEEK_SET) < 0)
		return (-1);
	while (read(champ->fd, &buf, 1) > 0 && i < COMMENT_LENGTH)
		champ->comment[i++] = buf;
	//printf("champ->comment: '%s'\n", champ->comment);
	return (0);
}

static int		get_champion(t_champ *champ)
{
	int		i;
	char	buf;

	i = 0;
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH
	+ sizeof(int) + 4 + COMMENT_LENGTH, SEEK_SET) < 0)
		return (-1);
	while (read(champ->fd, &buf, 1) > 0 && i < CHAMP_MAX_SIZE)
		champ->code[i++] = buf;
	//printf("champ->code: ");
	//i = 0;
	//while (i < CHAMP_MAX_SIZE)
	//	printf("%c", champ->code[i++]);
	//printf("\n");
	return (0);
}

int		read_champ_data(t_env *env, int num_champs)
{
	int	i;

	i = 0;
    printf("Reading champ data...\n");
	while (i < num_champs)
	{
        printf("entered loop with %d...\n", i);
        printf("file_name %s\n", env->champs[i].filename);
		if (check_magic(&env->champs[i]) < 0 || get_name_and_size(&env->champs[i]) < 0 ||
		    get_comment(&env->champs[i]) < 0 || get_champion(&env->champs[i]) < 0)
			return (-1);
		else if (close(env->champs[i].fd) < 0)
			return (-1);
    	printf("Champ name for %d: %s\n", i, env->champs[i].name);
		i++;
	}
    i = 0;
    while (i < num_champs)
    {
		printf("%s\n", env->champs[i].name);
    	i++;
    }
   	printf("Exiting read_champ_data: %d\n", num_champs);
	return (0);
}
