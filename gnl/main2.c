#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int fd;
	int fd2;
	char	*test;
	char	*test2;

	if (argc != 3)
		return (0);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	test = get_next_line(fd);
	printf("%s\n", test);
	free (test);
	close (fd);

	test = get_next_line(fd);
	printf("%s\n-------------------\n", test);

	fd = open(argv[1], O_RDONLY);
	test = get_next_line(fd);
	test2 = get_next_line(fd2);
	while (test && test2)
	{
		printf("%s", test);
		printf("%s", test2);
		test = get_next_line(fd);
		test2 = get_next_line(fd2);
	}

	return (0);
}
