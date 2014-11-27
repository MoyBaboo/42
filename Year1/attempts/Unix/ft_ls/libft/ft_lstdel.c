/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:18:45 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 20:18:47 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst)->next != NULL)
	{
		(del)((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
	}
	(del)((*alst)->content, (*alst)->content_size);
	free(alst);
	alst = NULL;
	return ;
}
