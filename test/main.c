#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = NULL;
/*
	printf("%d\n", get_next_line(fd, *line));
	printf("%s", *line);
	get_next_line(fd, *line);
	printf("%s", *line);
	get_next_line(fd, *line);
	printf("%s", *line);
	get_next_line(fd, *line);
	printf("%s", *line);
	get_next_line(fd, *line);
	printf("%s", *line);
	return (0);
*/

	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	return 0;
}
