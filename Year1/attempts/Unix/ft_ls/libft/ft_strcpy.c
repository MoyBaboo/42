/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:59:45 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 16:59:47 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;
	int		lend;
	int		lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (lens > lend)
	{
		dst = (char*)src;
		return (dst);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
