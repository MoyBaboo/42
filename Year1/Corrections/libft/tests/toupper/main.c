/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:37:52 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:37:53 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int 	main(int ac, char **av)
{
	char	*my_toupp;
	char	*sys_toupp;
	int		i = 0;

	if (ac == 2)
	{
		my_toupp = strdup(av[1]);
		sys_toupp = strdup(av[1]);
		while (my_toupp[i] != '\0')
		{
			my_toupp[i] = ft_toupper(my_toupp[i]);
			i++;
		}
		i = 0;
		while (sys_toupp[i] != '\0')
		{
			sys_toupp[i] = toupper(sys_toupp[i]);
			i++;
		}
		if (strcmp(my_toupp, sys_toupp) == 0)
		{
			printf("\033[1;33;32mft_toupper and toupper both returned the same values\033[0m\n");
			return (SUCCESS);
		}
		printf("\033[1;33;31m[0mft_toupper returned %s while toupper returned %s\033[0m\n", my_toupp, sys_toupp);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one char string to be brought to uppercase\033[0m\n");
	return (FAILURE);
}
