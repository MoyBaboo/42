/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:36:16 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:36:17 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_cpy;
	char	*sys_cpy;
	int 	stop;

	if (ac == 4)
	{
		stop = atoi(av[3]);
		my_cpy = strdup(av[1]);
		sys_cpy = strdup(av[1]);
		my_cpy = ft_strncpy(my_cpy, av[2], stop);
		sys_cpy = strncpy(sys_cpy, av[2], stop);
		if ((strcmp(my_cpy, sys_cpy) == 0))
		{
			printf("\033[1;33;32mNative strncpy and ft_strncpy both returned : %s\033[0m\n", sys_cpy);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strncpy returned %s while ft_strncpy returned %s\033[0m\n", sys_cpy, my_cpy);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters followed by a number n so that the n first characters of the second one get copied in the first one\033[0m\n");
	return (FAILURE);
}
