/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:59:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/04 15:17:55 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "op.h"
# include "../../libft/libft.h"
# define MAX_LINES 200

typedef	struct	s_src_line
{
	char	*data;
	char	*label;
	int		acb;
	int		*params;
	int		opcode;
	int		bytes;
}				t_src_line;

int			is_valid_source(int fd);
int			is_comment(char *line);
t_src_line	*get_params(t_src_line *lines);

#endif
