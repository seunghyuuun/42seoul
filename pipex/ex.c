/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:11:34 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/24 17:48:40 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	realex(t_piparg *arg, char **envp, int i, int fdout)
{
	int	size;
	int	outwrite;
	int	well;

	size = 0;
	while (arg->cmd[size])
		size++;
	if (i == size - 1)
		outwrite = arg->inout[1];
	else
		outwrite = fdout;
	dup2(arg->inout[0], 0);
	dup2(outwrite, 1);
	well = execve(arg->cmdpath[i], arg->cmd[i], envp);
	if (well == -1)
		erasearg(arg, "errno");
}

void	waiting(void)
{
	pid_t	pid;

	pid = 1;
	while (pid != -1)
		pid = waitpid(0, 0, WNOHANG);
}

void	piping(t_piparg *arg, char **envp, int size)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	i = 0;
	if (pipe(fd) == -1)
		erasearg(arg, "errno");
	pid = fork();
	while (pid && i < size - 1)
	{
		if (pid == -1)
			erasearg(arg, "errno");
		close(arg->inout[0]);
		close(fd[1]);
		arg->inout[0] = fd[0];
		i++;
		if (pipe(fd) == -1)
			erasearg(arg, "errno");
		pid = fork();
	}
	close(fd[0]);
	if (!pid)
		realex(arg, envp, i, fd[1]);
	close(arg->inout[0]);
	waiting();
}
