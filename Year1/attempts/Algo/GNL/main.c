/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:25:27 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/11 19:25:29 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				main(void)
{
	char	*line;
	int		fd;
	int 	fd2;

//	if ((line = (char *)malloc(sizeof(char) * 1)) == NULL)
//		return (0);
	fd = open("test2.txt", O_RDONLY);
	fd2 = open ("test.txt", O_RDONLY);
/*	while ((ret = get_next_line(fd, &line)) != TO_END)
	{
		printf("next line according to main %s\n", line);
		printf("%d\n", ret);
	}*/
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	get_next_line(fd2, &line);
	printf("next line of fd2 %d according to main %s\n\n", fd2, line);
	get_next_line(fd, &line);
	printf("next line of fd %d according to main %s\n\n", fd, line);
	return (0);
}
