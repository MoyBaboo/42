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
	char	*trim;
	int 	len;

	if (ac == 2)
	{
		trim = ft_strtrim(av[1]);
		len = strlen(trim);
		if (trim[0] != ' ' && trim[0] != '\t' && trim[0] != '\n' && trim[0] != '\b' &&
			trim[(len - 1)] != ' ' && trim[(len - 1)] != '\t' && trim[(len - 1)] != '\n' && trim[(len - 1)] != '\b')
		{
			printf("\033[1;33;32mTrimmed string is : [START]%s[END]\033[0m\n", trim);
			return (SUCCESS);
		}
		printf("\033[1;33;31mTrimmed string is : [START]%s[END]\033[0m\n", trim);
		return (FAILURE);
	}
	printf("\033[1;33;33mPlease input one string of characters\033[0m\n");
	return (1);
}
