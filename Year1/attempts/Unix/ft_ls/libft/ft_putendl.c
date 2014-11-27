/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:38:12 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 16:38:15 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl(char const *s)
{
	int		l;

	l = ft_strlen(s);
	write(1, s, l);
	ft_putchar('\n');
	return ;
}
