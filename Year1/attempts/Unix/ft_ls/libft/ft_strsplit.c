/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 16:18:42 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/14 16:18:44 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*ft_fill_tab(char const *s, int flag, char *split_tab, char c)
{
	int		i;

	i = 0;
	while (s[i + flag] != '\0' && s[i + flag] != c)
	{
		split_tab[i] = s[i + flag];
		i++;
	}
	split_tab[i] = '\0';
	return (split_tab);
}

static int	ft_strlen_split(char const *s, int flag, char c)
{
	int		len;

	len = 0;
	while (s[flag + len] != c && s[flag + len] != '\0')
		len++;
	return (len);
}

static int	ft_split_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		if (s[i] == '\0')
			return (count);
		i++;
	}
	return (count + 1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count;
	int		f;
	int		len;
	int		flag;
	char	**split_tab;

	if (s == NULL)
		return (NULL);
	count = ft_split_count(s, c);
	if ((split_tab = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
		return (NULL);
	f = -1;
	flag = 0;
	while (s[flag] != '\0' && f++ < count)
	{
		while (s[flag] == c)
			flag++;
		len = ft_strlen_split(s, flag, c);
		if ((split_tab[f] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		split_tab[f] = ft_fill_tab(s, flag, split_tab[f], c);
		flag += len;
	}
	split_tab[f] = 0;
	return (split_tab);
}
