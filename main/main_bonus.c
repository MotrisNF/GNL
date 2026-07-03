#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main (int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	int fd3 = open(argv[3], O_RDONLY);
	char *line = get_next_line(fd);
	char *line2 = get_next_line(fd2);
	char *line3 = get_next_line(fd3);
	while (line || line2 || line3)
	{
    	if (line)
		{
        	printf("%s", line);
		}
    	if (line2)
		{
        	printf("%s", line2);
		}
		if (line3)
		{
        	printf("%s", line3);
		}

    	free(line);
    	free(line2);
		free(line3);

    	line = get_next_line(fd);
    	line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
	}
		free(line);
		free(line2);
		free(line3);
	
		close(fd);
		close(fd2);
		close(fd3);
		return (0);

}