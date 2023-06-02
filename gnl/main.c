#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int fd;
	char	*test;

	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	test = get_next_line(fd);
	while (test)
	{
		printf("%s", test);
		free (test);
		test = get_next_line(fd);
	}
	/*printf("%s", test);*/
	return (0);
}
