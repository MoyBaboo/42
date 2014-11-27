/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:36:56 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:37:00 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_str;
	char	*sys_str;
	int 	stop;

	if (ac == 4)
	{
		stop = atoi(av[3]);
		my_str = ft_strnstr(av[1], av[2], stop);
		sys_str = strnstr(av[1], av[2], stop);
		if ((my_str == NULL && sys_str == NULL) || (my_str != NULL && sys_str != NULL && strcmp(my_str, sys_str) == 0))
		{
			printf("\033[1;33;32mNative strnstr and ft_strnstr both returned the same pointer\033[0m\n");
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strnstr returned %s while ft_strnstr returned %s\033[0m\n", sys_str, my_str);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters followed by a number n so that the first occurence of the second string is located in the n first characters of the first string\033[0m\n");
	return (INPUT_FAILURE);
}

