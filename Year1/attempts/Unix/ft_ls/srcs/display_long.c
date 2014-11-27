/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 22:18:46 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/20 22:18:48 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*sort_list(t_file *file, int opt)
{
	if (opt != 0)
		return (file);
	return (NULL);
}

int		disp_vis_long(t_file *file, int opt)
{
	if (opt % 7 != 0)
		file = sort_list(file, opt);
	while (file->next != NULL)
	{
		if (file->name[0] != '.')
		{
			ft_putendl(file->name);
			ft_putendl("DATA STORED");
			ft_putstr("type: ");
			ft_putchar((get_type(file->type)));
			ft_putchar('\n');
			ft_putstr("mode: ");
			ft_putstr(file->mode);
			ft_putchar('\n');
			ft_putstr("number of links: ");
			ft_putnbr(file->lnk_nb);
			ft_putchar('\n');
			ft_putstr("uid: ");
			ft_putstr(file->uid);
			ft_putchar('\n');
			ft_putstr("ctime: ");
			ft_putnbr(file->modif);
			ft_putchar('\n');
			ft_putstr("date: ");
			ft_putstr(file->disp_date);
			ft_putchar('\n');
		}
		file = file->next;	
	}
	return (SUCCESS);
}

char	get_type(int type)
{
	if ((type == DT_UNKNOWN))
		return ('?');
	if ((type == DT_FIFO))
		return ('p');
	if ((type == DT_CHR))
		return ('c');
	if ((type == DT_DIR))
		return ('d');
	if ((type == DT_BLK))
		return ('b');
	if ((type == DT_REG))
		return ('-');
	if ((type == DT_LNK))
		return ('l');
	if ((type == DT_SOCK))
		return ('s');
	if ((type == DT_WHT))
		return (' ');
	return ('0');
}

int		disp_all_long(t_file *file, int opt)
{
	if (opt % 7 != 0)
		file = sort_list(file, opt);
	while (file->next != NULL)
	{
		ft_putendl(file->name);
		ft_putendl("DATA STORED");
		ft_putstr("type: ");
		ft_putchar((get_type(file->type)));
		ft_putchar('\n');
		ft_putstr("mode: ");
		ft_putstr(file->mode);
		ft_putchar('\n');
		ft_putstr("number of links: ");
		ft_putnbr(file->lnk_nb);
		ft_putchar('\n');
		ft_putstr("uid: ");
		ft_putstr(file->uid);
		ft_putchar('\n');
		ft_putstr("ctime: ");
		ft_putnbr(file->modif);
		ft_putchar('\n');
		ft_putstr("date: ");
		ft_putstr(file->disp_date);
		ft_putchar('\n');
		file = file->next;	
	}
	return (SUCCESS);
}

int		display_long(t_file *file, int opt)
{
	if (opt % 2 == 0)
		disp_all_long(file, opt);
	else
		disp_vis_long(file, opt);
	return (SUCCESS);
}
