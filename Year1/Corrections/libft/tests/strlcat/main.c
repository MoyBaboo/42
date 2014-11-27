/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:35:48 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 19:35:50 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int		main(int ac, char **av)
{
	int		my_icat;
	int 	sys_icat;
	char 	*av_one_cpy;
	int 	len;

	if (ac == 4)
	{
		len = atoi(av[3]);
		av_one_cpy = strdup(av[1]);
		my_icat = ft_strlcat(av_one_cpy, av[2], len);
		sys_icat = strlcat(av[1], av[2], len);
		if (my_icat == sys_icat && strcmp(av_one_cpy, av[1]) == 0)
		{
			printf("\033[1;33;32mNative strlcat and ft_strlcat both returned : %d\033[0m\n", sys_icat);
			printf("\033[1;33;32mNative strlcat and ft_strlcat both concatenated : %s\033[0m\n", av[1]);
			return (SUCCESS);
		}
		if (my_icat == sys_icat && strcmp(av_one_cpy, av[1]) != 0)
		{
			printf("\033[1;33;32mNative strlcat and ft_strlcat both returned : %d\033[0m\n", sys_icat);
			printf("\033[1;33;31mNative strlcat concatenated : %s while ft_strlcat concatenated : %s\033[0m\n", av[1], av_one_cpy);
			return (FAILURE);
		}
		if (my_icat != sys_icat && strcmp(av_one_cpy, av[1]) != 0)
		{
			printf("\033[1;33;31mNative strlcat returned %d while ft_strlcat returned : %d\033[0m\n", sys_icat, my_icat);
			printf("\033[1;33;31mNative strlcat concatenated : %s while ft_strlcat concatenated : %s\033[0m\n", av[1], av_one_cpy);
			return (FAILURE);
		}
		if (my_icat != sys_icat && strcmp(av_one_cpy, av[1]) == 0)
		{
			printf("\033[1;33;31mNative strlcat returned %d while ft_strlcat returned : %d\033[0m\n", sys_icat, my_icat);
			printf("\033[1;33;32mNative strlcat and ft_strlcat both concatenated : %s\033[0m\n", av[1]);
			return (FAILURE);
		}
	}
	printf("\033[1;33;33mPlease input two strings of characters to be concatenated followed by a number n representing the maximum length of conlcatenation\033[0m\n");
	return (INPUT_FAILURE);
}
