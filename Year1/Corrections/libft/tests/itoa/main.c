/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:43:09 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 21:25:06 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int		nb;
	int		i = 0;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if ((av[1][i] < '0' || av[1][i] > '9') && (av[1][i] != '+' && av[1][i] != '-'))
			{
				ft_putendl("You must enter a valid number, made of digits from 0 to 9");
				return (1);
			}
			i++;
		}
		nb = atoi(av[1]);
		printf("We used system atoi and then ran our itoa which returns the following char string : %s\n", ft_itoa(nb));
		return (0);
	}
	printf("Please input one number\n");
	return (1);
}
