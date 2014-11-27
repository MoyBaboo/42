/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 15:36:25 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/23 15:36:27 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_horiz_size(t_tmp *content, t_map *map)
{
	map->horiz = content->len;
	if (map->horiz == 0)
	{
		ft_putendl("Map is invalid : must be at least one unit wide");
		exit (FAILURE);
	}
	while (content->next != NULL)
	{
		if (map->horiz != content->len)
		{
			ft_putendl("Map is invalid: not all lines are the same length");
			exit (FAILURE);
		}
		content = content->next;
	}
	content = content->prev->prev;
	map->horiz = 0;
	while (content->line[map->horiz])
		map->horiz++;
	map->horiz++;
	return (SUCCESS);
}

void 	get_vert_size(t_tmp *content, t_map *map)
{
	map->vert = 0;
	while (content->next != NULL)
	{
		map->vert++;
		content = content->next;
	}
	return ;
}

t_tmp	*read_input(int fd, char **line, t_tmp *content)
{
	if ((content = (t_tmp*)malloc(sizeof(t_tmp))) == NULL ||
		(content->line = (char**)malloc(sizeof(char**))) == NULL)
		return (NULL);
	if (get_next_line(fd, line) != TO_END)
	{
		content->len = ft_strlen(*line);
		content->line = ft_strsplit(*line, ' ');
		content->next = read_input(fd, line, content->next);
		content->next->prev = content;
		return (content);
	}
	content->line = NULL;
	content->next = NULL;
	return (content);
}

int 	**get_values(t_tmp *content, t_map *map)
{
	int 	i;
	int 	j;

	i = 0;
	if (!(map->values = (int**)malloc(sizeof(int) * (map->vert + 1))))
		return (NULL);
	while (i < map->vert)
	{
		if (!(map->values[i] = (int*)malloc(sizeof(int) * (map->horiz + 1))))
			return (NULL);
		j = 0;
		while (j < map->horiz)
		{
			map->values[i][j] = ft_atoi(content->line[j]);
			j++;
		}
		i++;
		content = content->next;
		free(content->prev);
	}
	return (map->values);
}

t_map	*get_map(int fd, char **line)
{
	t_map		*map;
	t_tmp		*content;

	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL ||
		(content = (t_tmp*)malloc(sizeof(t_tmp))) == NULL)
		return (NULL);
	content = read_input(fd, line, content);
	map->vert = 0;
	get_vert_size(content, map);
	get_horiz_size(content, map);
	map->values = get_values(content, map);
	return (map);
}
