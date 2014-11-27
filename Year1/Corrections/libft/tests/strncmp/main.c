/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:36:07 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:36:09 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int 	my_diff;
	int 	sys_diff;
	int 	stop;

	if (ac == 4)
	{
		stop = atoi(av[3]);
		my_diff = ft_strncmp(av[1], av[2], stop);
		sys_diff = strncmp(av[1], av [2], stop);
		if (my_diff == sys_diff)
		{
			printf("\033[1;33;32mNative strncmp and ft_strncmp both returned : %d\033[0m\n", sys_diff);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strncmp returned %d while ft_strncmp returned %d\033[0m\n", sys_diff, my_diff);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters to be lexicographically compared, followed by a number n representing the nth character at which you would like to stop comparing them\033[0m\n");
	return (FAILURE);
}
