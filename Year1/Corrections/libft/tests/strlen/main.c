/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:43:09 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 20:06:32 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int 	sys_len;
	int 	my_len;

	if (ac == 2)
	{
		sys_len = strlen(av[1]);
		my_len = ft_strlen(av[1]);
		if (sys_len == my_len)
		{
			printf("\033[1;33;32mNative strlen and ft_strlen both returned: %d\033[0m\n", sys_len);
			return (SUCCESS);
		}
		printf("\033[1;33;31mNative strlen returned : %d while ft_strlen returned : %d\033[0m\n", sys_len, my_len);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one string of characters to be measured\033[0m\n");
	return (INPUT_FAILURE);
}
