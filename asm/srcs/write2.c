/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:48:55 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/13 13:43:39 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	reverse_bytes(int *mem, size_t size)
{
    int		j;
    int		i;
    char	*tmp;
    char	*ptr;

    j = 0;
    i = 0;
    ptr = (char *)mem;
    tmp = (char *)malloc(size);
    ft_memcpy(tmp, mem, size);
    while (i >= 0)
    {
        ptr[j] = tmp[i];
        j++;
        i--;
    }
    free(tmp);
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
                printf("paramater is %s\n", lines[i].params[p]);
                if (lines[i].params[p][0] == 'r')
                    write_register(lines[i].params[p], fd);
                else if (ft_strchr(lines[i].params[p], LABEL_CHAR) != NULL)
                    write_label_adrs(lines[i].params[p], fd);
                else if (lines[i].params[p][0] == DIRECT_CHAR)
                    write_direct(lines[i], fd, p);
                else if (ft_isdigit(lines[i].params[p][0]))
                    write_indirect(lines[i].params[p], fd);
                p++;
            }
        }
        i++;
    }
}
