/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:26:07 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/13 14:26:08 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

/*
*** SYSTEM LIBRARIES
*/
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pwd.h>
# include <time.h>

/*
*** LIBFT HEADER
*/
# include "../libft/libft.h"

/*
*** STRUCTURE
*/
typedef struct 			s_file
{
	int					type;
	char				*mode;
	int					lnk_nb;
	char				*uid;
	time_t				modif;
	char				*disp_date;
	int					size;
	char				*name;
	struct s_file		*next;
	struct s_file		*prev;
}						t_file;

/*
*** FUNCTIONS
*/
int		display_dir(const char *name, int opt);
int		display_long(t_file *file, int opt);
int		disp_all_long(t_file *file, int opt);
int		disp_vis_long(t_file *file, int opt);
char	*get_mode(mode_t mode);
char	get_type(int type);
int		parse_opt(const char *opt);
t_file	*sort_list(t_file *file, int opt);
t_file	*to_tab(const char *name, int opt, DIR *dir, struct dirent *dir_p);



#endif
