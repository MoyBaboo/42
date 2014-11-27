/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:37:23 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:37:25 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	char	*my_str;
	char	*sys_str;

	if (ac == 3)
	{
		my_str = ft_strstr(av[1], av[2]);
		sys_str = strstr(av[1], av[2]);
		if (my_str == sys_str)
		{
			printf("\033[1;33;32mNative strstr and ft_strstr both returned the same pointer\033[0m\n");
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strstr returned %s while ft_strstr returned %s\033[0m\n", sys_str, my_str);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input two strings of characters so that the first occurence of the second string is located in the first string\033[0m\n");
	return (FAILURE);
}
