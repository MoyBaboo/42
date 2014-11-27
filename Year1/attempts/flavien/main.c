#include "get_next_line.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int				get_next_line(int const fd, char **line);

/*int		main()
{
	char	*line;
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}*/

int		main()
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	printf("finish\n");
	return (0);
}
