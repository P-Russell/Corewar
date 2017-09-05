/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:59:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/05 11:07:02 by prussell         ###   ########.fr       */
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
	long	params[MAX_ARGS_NUMBER];
	int		opcode;
	int		bytes;
}				t_src_line;


int		is_valid_fd(int fd);
int		is_comment(char *line);
int		is_opcode(char *line);
int		is_label(char *line);
t_src_line	*get_params(t_src_line *lines);

#endif
