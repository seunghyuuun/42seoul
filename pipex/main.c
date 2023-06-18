//#include "pipe.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	***cmdmkr(int argc, char **argv);
char	**pathmkr(char ***cmd, char **envp);
//int	ft_printf(const char *str, ...);

int	main(int argc, char **argv, char **envp)
{
	char	***cmd;
	char	**cmdpath;
	int inout[2];
	pid_t pid;

	if (argc < 5)
	{
		//ft_printf("more argv\n");
		printf("more argv\n");
		return (-1);
	}
	cmd = cmdmkr(argc, argv);
	if (!cmd)
	{
		printf("alloc fail\n");
		return (-1);
	}
	cmdpath = pathmkr(cmd, envp);
	if (!cmdpath)
	{
		printf("alloc fail\n");
		return (-1);
	}
	inout[0] = open(argv[1], O_RDWR);
	inout[1] = open(argv[argc - 1], O_RDWR);
	pid = fork();
	if (!pid)
		piping(cmd, cmdpath, envp, inout, 0);
	return (0);
}
