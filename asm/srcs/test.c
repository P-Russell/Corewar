/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:40:11 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/04 15:50:56 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int			i;
	t_src_line	*test_data;

	test_data = (t_src_line *)malloc(sizeof(t_src_line) * 2);
	i = 0;
	test_data[0].data = "l2:	sti r1, %:live, %1";
	test_data[1].data = "and r1, %0, r1";
	test_data = get_params(test_data);
	while (i < 2)
	{
		printf("Paramater 1 is %d\n", test_data[i].params[0]);
		printf("Paramater 2 is %d\n", test_data[i].params[1]);
		printf("Paramater 3 is %d\n", test_data[i].params[2]);
		printf("Paramater 4 is %d\n", test_data[i].params[3]);
		i++;
	}
	return (EXIT_SUCCESS);
}
