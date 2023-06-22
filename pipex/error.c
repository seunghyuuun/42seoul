/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:34:38 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/22 15:56:47 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	emptyout(t_piparg *arg, int outfile)
{
	char	*tempfile;
	int		fd;
	pid_t	pid;
	char	*cmdd[2];

	cmdd[1] = 0;
	cmdd[0] = "/bin/cat";
	tempfile = nonexitpath();
	fd = open(tempfile, O_CREAT, 0777);
	ft_printf("%s : %d\n", tempfile, fd);
	pid = fork();
	if (!pid)
	{
		dup2(outfile, 1);
		dup2(fd, 0);
		execve(cmdd[0], cmdd, arg->envp);
	}
	waitpid(pid, 0, 0);
	unlink(tempfile);
	free(tempfile);
	exit (-1);
}

void	autoerror(t_piparg *arg)
{
	char	*str;

	str = strerror(errno);
	write(2, str, ft_strlen(str));
	emptyout(arg, arg->inout[1]);
}

void	manualerror(t_piparg *arg, char *str)
{
	if (ft_strncmp(str, "more argv\n", 100) == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strncmp(str, "alloc fail\n", 100) == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strncmp(str, "command not found\n", 100) == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strncmp(str, "errno", 100) == 0)
		autoerror(arg);
	emptyout(arg, arg->inout[1]);
}
