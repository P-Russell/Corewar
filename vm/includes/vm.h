#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "op.h"
# include "../../libft/libft.h"

# define PARAM_ERROR "./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."

typedef	struct		s_core
{
	char			value[3];
	unsigned char	raw;
	unsigned int	champ_num;
}					t_core;

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
	t_core			*pc;
	int				carry;
	unsigned int	load_address;
	unsigned char	reg[REG_NUMBER * REG_SIZE + 1];
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
int		read_champ_data(t_champ *champs, int num_players);

#endif
