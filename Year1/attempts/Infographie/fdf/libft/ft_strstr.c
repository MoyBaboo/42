/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 17:10:59 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 17:11:07 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		start;
	int		i;

	if (s2[0] == '\0')
		return ((char*)s1);
	start = 0;
	i = 0;
	while (s1[start + i] != '\0')
	{
		while (ft_memcmp(&(s1[start + i]), &(s2[i]), 1) == 0)
		{
			i++;
			if (s2[i] == '\0')
				return ((char *)s1 + start);
			if (ft_memcmp(&(s1[start + i]), &(s2[i]), 1) != 0)
				start += (i - 1);
		}
		start++;
		i = 0;
	}
	return (NULL);
}
