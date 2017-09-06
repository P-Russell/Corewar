/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:59:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/06 14:31:36 by prussell         ###   ########.fr       */
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
	char		*data;
	char		*label;
	int			acb;
	char		*params[MAX_ARGS_NUMBER];
	int			opcode;
	int			bytes;
}				t_src_line;

int				is_valid_fd(int fd);
int				is_comment(char *line);
int				is_opcode(char *line);
int				is_label(char *line);
t_src_line		*get_params(t_src_line *lines);
void			print_struct(t_src_line*lines);
int				assemble(int fd);
char			**core_line_split(char const *s);

#endif
