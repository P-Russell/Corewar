/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:33:33 by prussell          #+#    #+#             */
/*   Updated: 2017/09/12 11:29:55 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	read_in_comment(char *line, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"' && line[++i])
		while (line[i] && line[i] != '"' && j < COMMENT_LENGTH)
			name[j++] = line[i++];
	if (line[i] != '"')
		ft_putendl_fd("Problem with comment", 2);
}

static void	read_in_name(char *line, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"' && line[++i])
		while (line[i] && line[i] != '"' && j < PROG_NAME_LENGTH)
			name[j++] = line[i++];
	if (line[i] != '"')
		ft_putendl_fd("Problem with name", 2);
}

int			init_header_var(t_header *head, int fd)
{
	char	*line;
	int		name_found;
	int		comment_found;

	ft_bzero(head->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(head->comment, COMMENT_LENGTH + 1);
	head->magic = COREWAR_EXEC_MAGIC;
	head->prog_size = 42;
	name_found = 0;
	comment_found = 0;
	while (get_next_line(fd, &line) && (!name_found || !comment_found))
	{
		if (line && ft_strstr(line, NAME_CMD_STRING) && (name_found = 1))
			read_in_name(line, head->prog_name);
		else if (line && ft_strstr(line, COMMENT_CMD_STRING) && (comment_found = 1))
			read_in_comment(line, head->comment);
		ft_strdel(&line);
	}
	return (0);
}

char	*exe_name(char *name)
{
	int 	i;
	int		j;
	char	*exe;
	char	**split;

	i = 0;
	j = 0;
	if (!(split = ft_strsplit(name, '/')))
		return (NULL);
	while (split[j])
		j++;
	j--;
	while (split[j][i] && split[j][i] != '.')
		i++;
	if (split[j][i] != '.' || !(exe = (char *)malloc(sizeof(char) * (i + 4))))
		return (NULL);
	exe[i + 4] = '\0';
	i = 0;
	while (split[j][i] != '.')
	{
		exe[i] = split[j][i];
		i++;
	}
	ft_strcpy(exe + i, ".cor");
	ft_matrixdel((void **)split);
	return (exe);
}

int		init_bin_var(t_binary *bin, int fd, char *name)
{
	init_header_var(&(bin->header), fd);
	bin->name = exe_name(name);
	printf("%s\n", bin->name);
	return (1);
}
