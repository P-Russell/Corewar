/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:59:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/12 13:21:54 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "op.h"
# include "../../libft/libft.h"
# define MAX_LINES 200


#include <stdio.h>

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct	s_binary
{
	t_header	header;
	int			fd;
	int			cursor;
	char		*name;
}				t_binary;

typedef	struct	s_src_line
{
	char		*label;
	int			acb;
	char		*params[MAX_ARGS_NUMBER];
	int			param_type[MAX_ARGS_NUMBER];
	int			opcode;
	int			bytes;
}				t_src_line;

typedef struct	s_norm
{
	int			i;
	int			j;
	char		*exe;
	char		**split;
}				t_norm;

int				is_valid_fd(int fd);
int				is_comment(char *line);
int				is_opcode(char *line);
int				is_label_address(char *line);
void			print_struct(t_src_line*lines);
void            champ_size(t_src_line *lines, t_binary *bin);
t_src_line		*build_line_data_struct(int fd);
char			**core_line_split(char const *s);
int				is_param(char *line);
int				get_params(t_src_line *lines);
int				get_acb(t_src_line *lines);
int				get_bytes(t_src_line *lines);
int				init_bin_var(t_binary *bin, int fd, char *name);
int				is_code_line(char **line);
int				write_cor(t_src_line *lines, t_binary *bin);

#endif
