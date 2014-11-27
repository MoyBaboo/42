/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:33:43 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:33:45 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_move;
	char	*sys_move;
	int 	len;

	if (ac == 4)
	{
		len = atoi(av[4]);
		sys_move = strdup(av[1]);
		my_move = strdup(av[1]);
		my_move = ft_memmove(my_move, av[2], len);
		sys_move = memmove(sys_move, av[2], len);
		if ((memcmp(my_move, sys_move) == 0))
		{
			printf("\033[1;33;32mNative memmove and ft_memmove both returned : %s\033[0m\n", sys_move);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative memmove returned %s while ft_memmove returned %s\033[0m\n", sys_move, my_move)
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two arguments followed by a number n so that n memory bits of second one get copied in the first one\033[0m\n");
	return (FAILURE);
}
