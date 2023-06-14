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
	int		i;
	pid_t	pid;

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
	//argc==5 가정하고 하기
	i = 0;
	while (i < argc - 3)
	{
		pid = fork();
		if (pid == 0)
			ft_exec(cmd, 
		i++;
	}
	return (0);
}
