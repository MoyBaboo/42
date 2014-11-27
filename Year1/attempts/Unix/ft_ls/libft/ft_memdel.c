/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:37:45 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 16:37:48 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_memdel(void **ap)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	c = (char*)malloc(sizeof(char*) * 1);
	free(c);
	while (((char**)ap)[i] != 0)
	{
		while ((*c = ((char**)ap)[i][j]) != 0)
		{
			free((void*)c);
			j++;
		}
		j = 0;
		i++;
	}
	ap = NULL;
	return ;
}
