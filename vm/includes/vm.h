#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "op.h"
# include "../../libft/libft.h"

# define PARAM_ERROR "./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."

typedef struct			s_op
{
	char				*name;
	int					nb_params;
	int					param_types[4];
	int					opcode;
	int					nb_cycles;
	char				*description;
	int					has_pcode;
	int					has_idx;
}						t_op;

typedef	struct		s_core
{
	char			value[3];
	unsigned char	raw;
	unsigned int	champ_num;	// Value will be 0 when no champ has written to / been loaded in to the register
}					t_core;

typedef struct		s_champ
{
	char			*filename;		//.cor file name
	int				fd;
	unsigned int	player_num;		//player num from 1 up to and including MAX_PLAYERS (usually 4)
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	size;			// size calculated by VM by counting bytes in executable code
	unsigned int	stated_size;	// size stated in .cor file
	unsigned int	cycles_to_exec;	// cost to execute instruction. to be decremented each cycle untill zero when instruction at PC is executed
	t_core			*pc;				// pointer to reg where current instruction to be executed is. After execution the PC is advanced to next op-code and cycles to exec gets initiallied to g_op_tab[opcode + 1].nb_cycles
	int				carry;
	unsigned int	load_address; 	// arena[load_address] will be player number and arena[load_address + 1] will be first byte of code 
	unsigned char	reg[REG_NUMBER * REG_SIZE + 1];
	unsigned char	code[MAX_CHAMP_SIZE + 1] //byte code to be read in to arena.
}					t_champ;

typedef struct		s_env
{
	unsigned int	dump;
	unsigned int	num_players;
	char			player_nums[MAX_PLAYERS]   // used to keep track of player numbers when user specifies player num
	t_champ			champs[MAX_PLAYERS];
	t_core			arena[MEM_SIZE]
}					t_env;

void	init_arena(t_env *env);									// bzeros value and set champ_num to 0 at all registers
int		init_env(int argc, char **argv, t_env *env);			//reads the command line parameters and set 
int		read_champ_data(t_champ *champs, int num_players);		//gets champion data from file discriptor

#endif