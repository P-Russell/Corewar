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
/*
 * reg
 * alive
 * player num;
 * size;
 * cyles to exec
 * carry?
 * *core_ptr // core_index /
 * stated_size
*/
}					t_core;

typedef struct		s_process
{
	int					pc;
	int					load_address;
	int					cycles_to_exec;
	t_core				*core_ptr;
	int					carry;
	int					alive;
	int					cycles_to_die;
	unsigned char		reg[REG_NUMBER + 1][REG_SIZE + 1];
}						t_process;

typedef struct		s_champ
{
	char			*filename;
	int				fd;
	unsigned int	player_num;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	size;
	unsigned int	stated_size;
	unsigned int	cycles_to_exec;
	t_core			*core_ptr;
	int				PC;
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
}					t_env;

void	init_arena(t_env *env);									
int		init_env(int argc, char **argv, t_env *env); 
int		read_champ_data(t_env *env, int num_players);
void	read_champs_into_core(t_env *env);
void	write_char_to_hex(unsigned char num, char *reg);
void	print_arena(t_env env);
int		is_valid_params(char **params);
int     is_direct(int acb, int param_num);
int     is_indirect(int acb, int param_num);
int     is_register(int acb, int param_num);
int     valid_reg(int num);

#endif
