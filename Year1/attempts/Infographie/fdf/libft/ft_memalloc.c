/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:37:34 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 16:37:37 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if ((mem = (void *)malloc(sizeof(unsigned char) * size)) == NULL)
		return (NULL);
	mem = 0;
	return (mem);
}
