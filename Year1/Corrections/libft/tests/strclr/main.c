/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:34:57 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:34:59 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int 	len;
	int 	i = 0;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		ft_strclr(av[1]);
		while (av[1][i] == '\0' && i < len)
			i++;
		if (i == len)
		{
			printf("\033[1;33;32mAll characters have successfully been transformed to \\0\033[0m\n");
			return (SUCCESS);
		}
		else
		{
			printf("\033[1;33;31mStrclr failed to transform chars after char %d to \\0\033[0m\n", i);
			return (FAILURE);
		}
	}
	printf("\033[1;33;33mPlease input one string of characters to clear\033[0m\n");
	return (FAILURE);
}
