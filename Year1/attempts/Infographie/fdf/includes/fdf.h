/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 22:39:18 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/21 22:39:20 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
*** SYSTEM LIBRARIES
*/
# include <mlx.h>

/*
*** LIBFT HEADER
*/
# include "../libft/libft.h"
# include "./get_next_line.h"

/*
*** STRUCTURE
*/
typedef struct 			s_env
{
	void				*mlx;
	void				*win;
}						t_env;

typedef struct 			s_map
{
	int					vert;
	int					horiz;
	int					**values;
}						t_map;

typedef struct 			s_tmp
{
	char				**line;
	int					len;
	struct s_tmp		*next;
	struct s_tmp		*prev;	
}						t_tmp;

/*
*** FUNCTIONS
*/
int		get_horiz_size(t_tmp *content, t_map *map);
void 	get_vert_size(t_tmp *content, t_map *map);
t_map	*get_map(int fd, char **line);
int 	**get_values(t_tmp *content, t_map *map);
int		get_next_line(int const fd, char **line);
t_tmp	*read_input(int fd, char **line, t_tmp *content);

#endif
