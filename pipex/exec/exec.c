#include "exec.h"

int	main(int argc, char **argv, char **envp)
{
	//char *test1 = "/Users/seunghy2/Desktop/pipex/hello.exe";
	//char *test2 = "ls";
	//char *const argv[] = {test2, NULL};
	//char *const envp[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki", NULL};

	char **path;
	char *cmd;
	char *temp;
	int	i = 0;

	if (argc == 1)
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
	i = 0;
	cmd = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd = ft_strjoin(temp, argv[1]);
		free(temp);
		if (access(cmd, X_OK) == 0)
			break;
		free (cmd);
		cmd = 0;
		i++;
	}
	if (!cmd)
		cmd = argv[1];
	printf("%s\n", cmd);
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);

	execve(cmd, &argv[1], envp);

	printf("END");

	return 0;
}
