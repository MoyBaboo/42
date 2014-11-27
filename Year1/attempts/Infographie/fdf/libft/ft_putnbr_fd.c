/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:09:16 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 21:36:35 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i < 0)
	{
		i = -i;
		ft_putchar_fd('-', fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	if (i < 10)
		ft_putchar_fd(i + '0', fd);
	return ;
}
