/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:35:26 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:35:27 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_cpy;
	char	*sys_cpy;

	if (ac == 3)
	{
		sys_cpy = strdup(av[1]);
		my_cpy = strdup(av[1]);
		my_cpy = ft_strcpy(my_cpy, av[2]);
		sys_cpy = strcpy(sys_cpy, av[2]);
		if ((strcmp(my_cpy, sys_cpy) == 0))
		{
			printf("\033[1;33;32mNative strcpy and ft_strcpy both returned : %s\033[0m\n", sys_cpy);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strcpy returned %s while ft_strcpy returned %s\033[0m\n", sys_cpy, my_cpy);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters so that the second one get copied in the first one\033[0m\n");
	return (FAILURE);
}
