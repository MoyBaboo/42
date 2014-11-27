/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:34:48 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:34:50 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_location;
	char 	*sys_location;

	if (ac == 3 && av[2][1] == '\0')
	{
		my_location = ft_strchr(av[1], av[2][0]);
		sys_location = strchr(av[1], av[2][0]);
		if (my_location == sys_location)
		{
			printf("\033[1;33;32mNative strchr and ft_strchr both returned the same pointer\033[0m\n");
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strchr returned %s while ft_strchr returned : %s\033[0m\n", sys_location, my_location);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one string of characters and one character which first occurence will be returned\033[0m\n");
	return (FAILURE);
}
