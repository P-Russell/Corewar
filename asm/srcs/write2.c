/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:48:55 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/14 16:23:50 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <string.h>

int		get_offset(t_src_line *lines, char *line)
{
	int		n;

	n = 0;
	while (lines[n].label != NULL || lines[n].opcode != 0)
	{
		printf("comparing %s and %s\n", line + 2, lines[n].label);
		while (lines[n].label == NULL)
			n++;
		if (ft_strncmp(lines[n].label, line + 2, ft_strlen(lines[n].label) - 1) == 0)
			break ;
		n++;
	}
	return (n);
}

int		check_idx(int op)
{
    int i;

    i = 0;
    while (g_op_tab[i].name != 0)
    {
        if (g_op_tab[i].opcode == op)
            return (g_op_tab[i].has_idx);
        i++;
    }
    return (-1);
}

void	write_bytes(int fd, t_src_line *lines)
{
    int	i;
    int	p;
    int	n;

    i = 0;
    n = 0;
    while (lines[i].label != NULL || lines[i].opcode != 0)
    {
        if (lines[i].opcode != 0)
        {
            p = 0;
            write_opcode_and_acb(lines[i], fd);
            while (lines[i].params[p] != NULL)
            {
                if (lines[i].params[p][0] == 'r')
                    write_register(lines[i].params[p], fd);
                else if (ft_strchr(lines[i].params[p], LABEL_CHAR) != NULL)
                    write_label_adrs(lines, lines[i].params[p], fd, i);
                else if (lines[i].params[p][0] == DIRECT_CHAR)
                    write_direct(lines[i], fd, p);
                else if (ft_isnumber(lines[i].params[p]))
                    write_indirect(lines[i].params[p], fd);
                p++;
            }
        }
        i++;
    }
}
