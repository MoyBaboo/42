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
	int 	nb;

	if (ac == 2)
	{
		nb = atoi(av[1]);
		ft_putnbr(nb);
		return (SUCCESS);
	}
	printf("\033[1;33;33mPlease input one number\033[0m\n");
	return (1);
}
