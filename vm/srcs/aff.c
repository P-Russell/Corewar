/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:32:39 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/21 13:25:17 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		aff(unsigned char reg)
{
	char	c;

	c = (char)(reg % 256);
	write(1, &c, 1);
	write(1, "\n", 1);
}
