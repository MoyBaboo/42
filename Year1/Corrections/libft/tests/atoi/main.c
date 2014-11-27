/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:43:09 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 20:35:23 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int 	my_atoi;
	int 	sys_atoi;

	if (ac == 2)
	{
		my_atoi = ft_atoi(av[1]);
		sys_atoi = atoi(av[1]);
		if (my_atoi == sys_atoi)
		{
			printf("\033[1;33;32mNative atoi an ft_atoi both returned : %d\033[0m\n", sys_atoi);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative atoi returned %d while ft_atoi returned : %d\033[0m\n", sys_atoi, my_atoi);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one number\033[0m\n");
	return (1);
}
