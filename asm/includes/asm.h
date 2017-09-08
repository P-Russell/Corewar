/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:59:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/08 08:35:20 by prussell         ###   ########.fr       */
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


#include <stdio.h>


typedef	struct	s_src_line
{
	char		*data;
	char		*label;
	int			acb;
	char		*params[MAX_ARGS_NUMBER];
	int			param_type[MAX_ARGS_NUMBER];
	int			opcode;
	int			bytes;
}				t_src_line;

int				is_valid_fd(int fd);
int				is_comment(char *line);
int				is_opcode(char *line);
int				is_label_address(char *line);
void			print_struct(t_src_line*lines);
int				assemble(int fd);
char			**core_line_split(char const *s);
int				is_param(char *line);
int				get_params(t_src_line *lines);
int				get_acb(t_src_line *lines);
int				get_bytes(t_src_line *lines);

#endif
