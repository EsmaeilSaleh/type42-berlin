#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		fd = open("tests/input.txt", O_RDONLY);
	char	*line;
	int		line_num = 1;

	if (fd < 0)
	{
		perror("Failed to open test file");
		return (1);
	}

	while ((line = get_next_line(fd)))
	{
		printf("Line %d: %s", line_num++, line);
		free(line);
	}
	close(fd);
	return (0);
}
