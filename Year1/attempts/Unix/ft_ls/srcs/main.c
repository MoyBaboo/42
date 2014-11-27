/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:25:56 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/13 14:25:58 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int 			i;
	int				opt;

	if (ac == 1)
		return (display_dir(".", 1));
	i = 1;
	opt = 1;
	while (i < ac && av[i][0] == '-')
	{
		opt *= parse_opt(av[i]);
		i++;
	}
	if (i == ac)
		return (display_dir(".", opt));
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putendl(":");
		display_dir(av[i], opt);
		if ((i + 1) != ac)
			ft_putchar('\n');
		i++;
	}
	return (SUCCESS);
}
