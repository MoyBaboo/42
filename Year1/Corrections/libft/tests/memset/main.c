/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:33:59 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:34:01 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_set;
	char	*sys_set;
	int 	len;

	if (ac == 4 && av[2][1] == '\0')
	{
		len = atoi(av[3]);
		if (len < 0)
		{
			printf("\033[1;33;33mLength must be superior or equal to 0\033[0m\n");
				return (INPUT_FAILURE);
		}
		sys_set = strdup(av[1]);
		my_set = strdup(av[1]);
		my_set = ft_memset(my_set, (int)av[2][0], len);
		printf("jerk");
		sys_set = memset(sys_set, (int)av[2][0], len);
		if ((memcmp(my_set, sys_set, len) == 0))
		{
			printf("\033[1;33;32mNative memset and ft_memset both returned : %s\033[0m\n", sys_set);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative memset returned %s while ft_memset returned %s\033[0m\n", sys_set, my_set);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one argument followed a char c and a number n so that c is copied in n memory bits of the first argument\033[0m\n");
	return (INPUT_FAILURE);
}

//FICHIER FONCTION MIS A JOUR VALEURS NEG!!
