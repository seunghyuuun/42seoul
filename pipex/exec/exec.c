#include "exec.h"

int	main(int argc, char **argv, char **envp)
{
	char **path;
	char *cmd;
	char *cmd2;
	char *temp;
	char **rargv;
	char **rargv2;
	int fdopen = open(argv[1], O_RDWR);
	int fdclose = open(argv[4], O_RDWR);
	int fd[2];
	pid_t pid;
	int	i = 0;

	if (argc < 4)
	{
		printf("argv need\n");
		return (-1);
	}
	while (envp[i])
	{
		if (!(ft_strncmp("PATH=", envp[i], ft_strlen("PATH="))))
			break;
		i++;
	}
	printf("%s\n", envp[i]);
	path = ft_split(envp[i] + ft_strlen("PATH="), ':');
	rargv = ft_split(argv[2], ' ');
	rargv2 = ft_split(argv[3], ' ');
	i = 0;
	cmd = 0;
	cmd2 = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd = ft_strjoin(temp, rargv[0]);
		free(temp);
		if (access(cmd, X_OK) == 0)
			break;
		free (cmd);
		cmd = 0;
		i++;
	}
	if (!cmd)
		cmd = rargv[0];
	printf("%s\n", cmd);
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd2 = ft_strjoin(temp, rargv2[0]);
		free(temp);
		if (access(cmd2, X_OK) == 0)
			break;
		free (cmd2);
		cmd2 = 0;
		i++;
	}
	if (!cmd2)
		cmd2 = rargv2[0];
	printf("%s\n", cmd2);
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);

	pipe (fd);
	pid = fork();
	if (!pid)
	{
		dup2(fdopen, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		execve(cmd, rargv, envp);
		return 0;
	}
	dup2(fd[0], 0);
	dup2(fdclose, 1);
	close(fd[1]);

	execve(cmd2, rargv2, envp);

	printf("END");

	return 0;
}
