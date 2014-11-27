/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:33:24 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:33:27 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_cpy;
	char	*sys_cpy;
	int 	len;

	if (ac == 4)
	{
		len = atoi(av[4]);
		sys_cpy = strdup(av[1]);
		my_cpy = strdup(av[1]);
		my_cpy = ft_memcpy(my_cpy, av[2], len);
		sys_cpy = memcpy(sys_cpy, av[2], len);
		if ((memcmp(my_cpy, sys_cpy) == 0))
		{
			printf("Native memcpy and ft_memcpy both returned : %s\n", sys_cpy);
			return (SUCCESS);
		}
		printf("Native memcpy returned %s while ft_memcpy returned %s\n", sys_cpy, my_cpy)
		return (FAILURE);
	}
	printf("Please input two arguments followed by a number n so that n memory bits of second one get copied in the first one\n");
	return (FAILURE);
}
