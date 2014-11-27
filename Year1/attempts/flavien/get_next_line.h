/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 17:30:11 by lvergero          #+#    #+#             */
/*   Updated: 2014/09/25 19:03:24 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
*** Macros
*/
# define	BUFF_SIZE 	1

# define	RET_EOL		0
# define	RET_EOF		-1
# define	RET_MIDL	1

# define	RET_OK		0
# define	RET_NOPE	-1

/*
*** System libraries
*/
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
*** Custom library
*/
//# include "libft/includes/libft.h"

/*
*** Custom definitions
*/
typedef struct 		s_read
{
	char			*current;
	char			*buf;
	unsigned int	start;
	unsigned int	end;
}					t_read;

/*
*** Functions' prototypes
*/
int		get_next_line(int const fd, char **line);
char	*ft_addstr(int const fd, char *buf, int flag);
int		ft_tcheck_n(char *str, char **line);

#endif
