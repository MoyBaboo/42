/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:31:20 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/27 21:04:05 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	**ft_arraydup(const void **array)
{
	void	**copy;
	size_t	h;
	size_t	l;

	h = 0;
	while (((unsigned char*)array[h]))
		h++;
	if (copy = (void**)malloc(sizeof(array[0][0]) * h) == NULL)
		return (NULL);
	copy[h] = 0;
	while (h-- >= 0)
	{
		l = 0;
		while (((unsigned char)array[h][l]))
		{
			if (!(copy[h][l] == malloc(sizeof(array[h][l]))))
				return (NULL);
			ft_memcpy(((unsigned char)copy[h][l])),
				((unsigned char)array[h][l]), 1);
			l++;
		}
		h--;
	}
	return (copy);
}
