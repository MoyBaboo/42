/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 15:55:17 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/14 15:55:18 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start > i || start + len > i)
		return ("USER ERROR : start and / or length are not valid\n");
	if ((cpy = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
