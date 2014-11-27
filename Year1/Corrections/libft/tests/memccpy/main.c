/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:32:57 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:32:59 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_cpy;
	char	*sys_cpy;
	int 	len;

	if (ac == 5 && av[3][1] == '\0')
	{
		len = atoi(av[4]);
		sys_cpy = strdup(av[1]);
		my_cpy = strdup(av[1]);
		my_cpy = ft_memccpy(my_cpy, av[2], av[3][0], len);
		sys_cpy = memccpy(sys_cpy, av[2], av[3][0], len);
		if ((strcmp(my_cpy, sys_cpy) == 0))
		{
			printf("\033[1;33;32mNative memccpy and ft_memccpy both returned : %s\033[0m\n", sys_cpy);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative memccpy returned \n%s\n while ft_memccpy returned \n%s\n\033[0m\n", sys_cpy, my_cpy);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two arguments followed by a char c and a number n so that n memory bits of second one get copied in the first one until c is found\033[0m\n");
	return (INPUT_FAILURE);
}
