/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:35:38 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:35:39 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char 	*my_dup;
	char 	*sys_dup;

	if (ac == 2)
	{
		my_dup = ft_strdup(av[1]);
		sys_dup = strdup(av[1]);
		if (strcmp(my_dup, sys_dup) == 0)
		{
			printf("\033[1;33;32mNative strdup and ft_strdup both returned : %s\033[0m\n", sys_dup);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strdup returned %s while ft_strdup returned %s\033[0m\n", sys_dup, my_dup);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one string of characters to be duplicated\033[0m\n");
	return (FAILURE);
}
