/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 17:30:01 by lvergero          #+#    #+#             */
/*   Updated: 2014/09/25 17:30:03 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && s2[i] != '\n')
	{
		s1[i] = s2[i];
		i++;
	}
	if (s2[i] == '\n')
		s1[i] = '\n';
	else
		s1[i] = '\0';
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strnew(unsigned int size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char*)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str = ft_strcpy((char *)str, (char *)s1);
	str = ft_strcat((char *)str, (char *)s2);
	return (str);
}


void	gnl_display(t_read *reading)
{
	int		i;

	i = 0;
//	printf("start = %u\n", reading->start);
//	printf("end gnl_display = %u\n", reading->end);
	while (reading->start + i <= reading->end)
	{
		write(1, &(reading->current[reading->start + i]), 1);
		i++;
	}
}

int		parser_gnl(t_read *reading)
{
	int		i;
	int		len;

	if (reading->buf[0] == '\0')
		return (RET_EOF);
	i = 0;
	while (reading->buf[i] != '\n' && reading->buf[i] != '\0' && i < BUFF_SIZE)
		i++;
	reading->end += i;
	len = (reading->end - reading->start) + 1;
	reading->current = (char*)malloc(sizeof(char) * (len));
	reading->current = ft_strjoin(reading->current, reading->buf);
	if (reading->buf[i] == '\n')
		return (RET_EOL);
	return (RET_MIDL);
}

int		read_line(int fd, t_read *reading)
{
	int		ret;
	int		go;

	reading->buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
 	while ((ret = read(fd, reading->buf, BUFF_SIZE)) != 0)
 	{
		if (ret == -1)
			return (RET_NOPE);
		go = parser_gnl(reading);
		if (go == RET_EOF)
			return (RET_EOF);
		ft_putstr(reading->current);
		if (go == RET_EOL)
		{
			write (1, "\n", 1);
//			gnl_display(reading);
			return (RET_OK);
		}
	}
	return (RET_OK);
}

int		get_next_line(int fd, char **line)
{
	static t_read		*reading = NULL;

	if (fd < 1 || BUFF_SIZE < 1)
		return (RET_NOPE);
	if (reading == NULL)
	{
		reading = (t_read *)malloc(sizeof(t_read));
		reading->end = 0;
	}
	reading->start = reading->end;
	reading->current = NULL;
	if ((read_line(fd, reading)) == RET_NOPE)
		return (RET_NOPE);
//	ft_putstr(reading->current);
//	write(1, "\n", 1);
	printf("Start is %u\n", reading->start);
	*line = &(reading->current[reading->start]);
	free(reading->buf);
	return (RET_OK);
}

