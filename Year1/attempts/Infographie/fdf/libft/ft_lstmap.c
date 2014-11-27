/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:28:54 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 20:28:56 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	lst_swap(t_list *lst, t_list *tmp)
{
	void	*ctnt;
	size_t	ctnt_s;

	ctnt = lst->content;
	ctnt_s = lst->content_size;
	if ((tmp = ft_lstnew(ctnt, ctnt_s)) == NULL)
		return (FAILURE);
	tmp = lst;
	return (SUCCESS);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	lst = (f)(lst);
	if (lst_swap(lst, tmp) == FAILURE)
		return (NULL);
	if (lst->next == NULL)
		return (tmp);
	start = tmp;
	while (lst->next != NULL)
	{
		lst = (f)(lst);
		if (lst_swap(lst, tmp->next) == FAILURE)
			return (NULL);
		tmp = tmp->next;
	}
	lst = (f)(lst);
	if (lst_swap(lst, tmp) == FAILURE)
		return (NULL);
	return (start);
}
