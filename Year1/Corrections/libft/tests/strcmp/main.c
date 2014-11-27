/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:35:17 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:35:18 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int 	my_diff;
	int 	sys_diff;

	if (ac == 3)
	{
		my_diff = ft_strcmp(av[1], av[2]);
		sys_diff = strcmp(av[1], av [2]);
		if (my_diff == sys_diff)
		{
			printf("\033[1;33;32mNative strcmp and ft_strcmp both returned : %d\033[0m\n", sys_diff);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strcmp returned %d while ft_strcmp returned %d\033[0m\n", sys_diff, my_diff);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters to be lexicographically compared\033[0m\n");
	return (FAILURE);
}
