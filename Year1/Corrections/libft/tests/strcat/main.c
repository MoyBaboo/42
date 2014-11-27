/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:34:26 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:34:30 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_cat;
	char 	*sys_cat;
	char 	*av_one_cpy;

	if (ac == 3)
	{
		av_one_cpy = strdup(av[1]);
		my_cat = ft_strcat(av_one_cpy, av[2]);
		sys_cat = strcat(av[1], av[2]);
		if (strcmp(my_cat, sys_cat) == 0)
		{
			printf("\033[1;33;32mNative strcat and ft_strcat both returned : %s\033[0m\n", sys_cat);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strcat returned %s while ft_strcat returned : %s\033[0m\n", sys_cat, my_cat);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters to be concatenated\033[0m\n");
	return (INPUT_FAILURE);
}
