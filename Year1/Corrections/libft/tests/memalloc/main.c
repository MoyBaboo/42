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
	int 	size;
	char	*my_malloc;

	if (ac == 2)
	{
		size = atoi(av[1]);
		my_malloc = (char*)ft_memalloc(size);
		if (my_malloc == 0)
		{
			printf("\033[1;33;32mMemory was allocated\033[0m\n");
			return (SUCCESS);
		}
		printf("\033[1;33;31mMemory was not allocated\033[0m\n");
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one number that will be the size of memmory allocation\033[0m\n");
	return (1);
}
