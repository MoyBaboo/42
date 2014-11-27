/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:17:57 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/14 17:17:59 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*get_mode(mode_t mode)
{
	char	*disp;

	if ((disp = (char*)malloc(sizeof(char) * 10)) == NULL)
		return (NULL);
	disp[0] = ((S_IRUSR(mode)) == 0) ? 'r' : '-';
	disp[1] = ((S_IWUSR(mode)) == 0) ? 'w' : '-';
	disp[2] = ((S_IXUSR(mode)) == 0) ? 'x' : '-';
	disp[3] = ((S_IRGRP(mode)) == 0) ? 'r' : '-';
	disp[4] = ((S_IWGRP(mode)) == 0) ? 'w' : '-';
	disp[5] = ((S_IXGRP(mode)) == 0) ? 'x' : '-';
	disp[6] = ((S_IROTH(mode)) == 0) ? 'r' : '-';
	disp[7] = ((S_IWOTH(mode)) == 0) ? 'w' : '-';
	disp[8] = ((S_IXOTH(mode)) == 0) ? 'x' : '-';
	disp[9] = '\0';
	return (disp);
}

t_file	*to_tab(const char *name, int opt, DIR *dir, struct dirent *dir_p)
{
	t_file			*file;
	struct stat 	*f_stat;
	struct passwd	*f_user;

	if ((file = (t_file*)malloc(sizeof(t_file))) == NULL ||
		(f_stat = (struct stat*)malloc(sizeof(struct stat))) == NULL ||
		(f_user = (struct passwd*)malloc(sizeof(struct passwd))) == NULL)
		return (NULL);
	if ((dir_p = readdir(dir)) != NULL)
	{
		file->prev = NULL;
		lstat(name, f_stat);
		file->type = dir_p->d_type;
		file->mode = get_mode(f_stat->st_mode);
		file->lnk_nb = f_stat->st_nlink;
		f_user = getpwuid(f_stat->st_uid);
		file->uid = f_user->pw_name;
		file->modif = f_stat->st_mtime;
		file->disp_date = ctime((const time_t*)&(f_stat->st_mtime));
		file->name = dir_p->d_name;
		file->next = to_tab(name, opt, dir, dir_p);
		file->next->prev = file;
		return (file);
	}
	closedir(dir);
	while (file->prev != NULL)
		file = file->prev;
	return (file);
}

int		parse_opt(const char *opt)
{
	int				ret;
	int				i;

	i = 1;
	ret = 1;
	while (opt[i] != '\0')
	{
		if (ft_memcmp(((const char*)&opt[i]), "a", 1) == 0)
			ret *= 2;
		else if (ft_memcmp(((const char*)&opt[i]), "l", 1) == 0)
			ret *= 3;
		else if (ft_memcmp(((const char*)&opt[i]), "R", 1) == 0)
			ret *= 5;
		else if (ft_memcmp(((const char*)&opt[i]), "t", 1) == 0)
			ret *= 7;
		else if (ft_memcmp(((const char*)&opt[i]), "r", 1) == 0)
			ret *= 11;
		i++;
	}
	return (ret);
}

int		display_dir(const char *name, int opt)
{
	DIR				*dir;
	struct dirent	*dir_p;
	t_file			*file;

	if ((dir = opendir(name)) == NULL)
	{
		ft_putstr(name);
		ft_putendl(" : directory can't be opened");
		exit (FAILURE);
	}
	if (opt == 1 && name[0] == '.' && name[1] == '\0')
	{
		while ((dir_p = readdir(dir)) != NULL)
		{
			if (dir_p->d_name[0] != '.')
				ft_putendl(dir_p->d_name);
		}
		return (SUCCESS);
	}
	dir_p = NULL;
	file = (opt % 3 == 0) ? to_tab(name, opt, dir, dir_p) : NULL;
	if (file != NULL)
		display_long(file, opt);
	else if (opt % 3 != 0 && opt % 2 == 0)
	{
		while ((dir_p = readdir(dir)) != NULL)
			ft_putendl(dir_p->d_name);
	}
	else if (opt % 3 != 0 && opt % 2 == 0)
	{
		while ((dir_p = readdir(dir)) != NULL)
		{
			if (dir_p->d_name[0] != '.')
				ft_putendl(dir_p->d_name);
		}
	}
	return (SUCCESS);
}
