#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	int fd1;
	int fd2;
	char *cmd[2];

	if (argc != 1)
		return (0);
	argv = 0;
	cmd[1] = 0;
	cmd[0] = "/bin/cat";
	fd1 = open("./aaa.txt", O_RDWR);
	fd2 = open("./bbb.txt", O_RDWR);

	dup2(fd1, 0);
	dup2(fd2, 1);
	execve(cmd[0], cmd, envp);
}
