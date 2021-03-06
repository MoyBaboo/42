/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:43:09 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 20:53:47 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int		i = 0;

	if (ac == 2)
	{
		printf("ft_isalnum returns:\n");
		while (av[1][i] != '\0')
		{
			printf("%d", ft_isalnum(av[1][i]));
			i++;
		}
		printf("\nnative isalnum returns:\n");
		i = 0;
		while (av[1][i] != '\0')
		{
			printf("%d", isalnum(av[1][i]));
			i++;
		}
		printf("\n");
		return (0);
	}
	printf("Please input one string of characters\n");
	return (1);
}
