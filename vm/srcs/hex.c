/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:17:53 by prussell          #+#    #+#             */
/*   Updated: 2017/09/23 11:47:27 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_char_to_hex(unsigned char num, char *reg)
{
	char 	hex[16];

	ft_strcpy(hex, "0123456789ABCDEF");
	if (num < 16)
	{
		reg[0] = '0';
		reg[1] = hex[num];
	}
	else
	{
		reg[0] = hex[(num / 16) % 16];
		reg[1] = hex[num % 16];
	}
}
