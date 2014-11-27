/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:37:41 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:37:44 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int 	main(int ac, char **av)
{
	char	*my_tolow;
	char	*sys_tolow;
	int		i = 0;

	if (ac == 2)
	{
		my_tolow = strdup(av[1]);
		sys_tolow = strdup(av[1]);
		while (my_tolow[i] != '\0')
		{
			my_tolow[i] = ft_tolower(my_tolow[i]);
			i++;
		}
		i = 0;
		while (sys_tolow[i] != '\0')
		{
			sys_tolow[i] = tolower(sys_tolow[i]);
			i++;
		}
		if (strcmp(my_tolow, sys_tolow) == 0)
		{
			printf("\033[1;33;32mft_tolower and tolower both returned the same values\033[0m\n");
			return (SUCCESS);
		}
		printf("\033[1;33;31mft_tolower returned %s while tolower returned %s\033[0m\n", my_tolow, sys_tolow);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one char string to be brought to lowercase\033[0m\n");
	return (FAILURE);
}
