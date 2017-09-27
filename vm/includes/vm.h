/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:27:13 by prussell          #+#    #+#             */
/*   Updated: 2017/09/26 15:39:28 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "op.h"
# include "../../libft/libft.h"


#include <stdio.h>


# define PARAM_ERROR "./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."

typedef	struct		s_core
{
	char			value[3];
	unsigned char	raw;
	unsigned int	champ_num;
}					t_core;

typedef struct			s_process
{
	int					pc;
	int					load_address;
	int					player_num;
	int					cycles_to_exec;
	int					carry;
	int					live_calls;
	unsigned char		reg[REG_NUMBER + 1][REG_SIZE + 1];
	struct s_process	*next;
}						t_process;

typedef struct		s_champ
{
	char			*filename;
	int				fd;
	int				player_num;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	size;
	unsigned int	stated_size;
	unsigned int	cycles_to_exec;
	int				pc;
	int				carry;
	unsigned int	load_address;
	unsigned char	code[CHAMP_MAX_SIZE + 1];
}					t_champ;

typedef struct		s_env
{
	unsigned int	dump;
	unsigned int	num_players;
	char			player_nums[MAX_PLAYERS];
	t_champ			champs[MAX_PLAYERS];
	t_core			arena[MEM_SIZE];
	t_process		*process;
}					t_env;

void		init_arena(t_env *env);									
int			init_env(int argc, char **argv, t_env *env); 
int			read_champ_data(t_env *env, int num_players);
void		read_champs_into_core(t_env *env);
void		write_char_to_hex(unsigned char num, char *reg);
void		print_arena(t_env env);
int			is_valid_params(char **params);
int			is_direct(int acb, int param_num);
int			is_indirect(int acb, int param_num);
int			is_register(int acb, int param_num);
int			valid_reg(int num);
int			value_from_core(t_core *arena, int pc, int size);
int			write_to_core(t_core *arena, int pc, int value, int size);
int			value_from_reg(unsigned char *reg);
int			little_to_big_endian(int nb);
int			ft_htoi(char *str, size_t len);
void		write_to_reg(unsigned char *reg, int value);
void		push_proc(t_process **head, t_process *new_p);
t_process	*new_proc(t_process *father, int pc);
t_process	*init_process(t_champ *champs, int num_players);
void		del_first_proc(t_process **head);
char		*ft_itoh(int val);
int			game_loop(t_env *env);
int			op_live(t_process *p, t_core *arena);
int			op_ld(t_process *p, t_core *arena);
int			op_st(t_process *p, t_core *arena);
int			op_add(t_process *p, t_core *arena);
int			op_sub(t_process *p, t_core *arena);
int			op_and(t_process *p, t_core *arena);
int			op_or(t_process *p, t_core *arena);
int			op_xor(t_process *p, t_core *arena);
int			op_zjump(t_process *p, t_core *arena);
int			op_ldi(t_process *p, t_core *arena);
int			op_sti(t_process *p, t_core *arena);
int			op_fork(t_process *p, t_core *arena);
int			op_lld(t_process *p, t_core *arena);
int			op_lldi(t_process *p, t_core *arena);
int			op_lfork(t_process *p, t_core *arena);
int			op_aff(t_process *p, t_core *arena);
int			ft_power(int a, int b);

typedef		int	(*op_ptr_t)(t_process *proc, t_core *arena);

#endif
