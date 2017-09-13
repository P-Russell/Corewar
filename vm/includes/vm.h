/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:15:30 by prussell          #+#    #+#             */
/*   Updated: 2017/09/13 14:40:45 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"

typedef struct		s_champ
{
	int				player_num;
	char			*name;
	char			*comment;
	int				carry;
	unsigned int	load_position;
	unsigned int	size;
	unsigned int	pc
	unsigned char	code[CHAMP_MAX_SIZE];
}					t_champ;

#endif
