/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:43:09 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/22 16:40:44 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int 	n;
	int 	i = 0;
	int 	len;
	char 	*late;

	if (ac == 3)
	{
		n = atoi(av[2]);
		len = strlen(av[1]);
		late = &(av[1][n - 1]);
		ft_bzero(av[1], n);
		while (i < n)
		{
			printf("Character %d is : %c\n", i, av[1][i]);
			i++;			
		}
		i = 0;
		while (i + n <= len)
		{
			printf("Character %d is : %c\n", n+i, late[i]);
			i++;
		}
		return (SUCCESS);
	}
	printf("\033[1;33;33mPlease input one string of characters to clear and a length to clear\033[0m\n");
	return (1);
}
