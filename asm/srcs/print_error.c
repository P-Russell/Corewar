/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:59:39 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/22 11:31:14 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_error(char *str, int line_num)
{
	ft_putstr(str);
	ft_putstr(" at line no: ");
	ft_putnbrnl(line_num + 1);
}
