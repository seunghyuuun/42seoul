/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:11:34 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/19 17:52:47 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	realex(t_piparg *arg, char **envp, int i, int fdout)
{
	dup2(arg->inout[0], 0);
	dup2(fdout, 1);
	execve(arg->cmdpath[i], arg->cmd[i], envp);
}

void	waiting(pid_t *pdarr, pid_t pid, int size)
{
	int	i;
	int	pidend;
	int	repeat;

	pdarr[size - 1] = pid;
	while (1)
	{
		i = 0;
		repeat = 0;
		while (i < size)
		{
			if (pdarr[i])
				pidend = waitpid(pdarr[i], NULL, WNOHANG);
			if (pidend)
				pdarr[i] = 0;
			if (pdarr[i])
				repeat++;
			i++;
		}
		if (!repeat)
			break ;
	}
}

void	piping(t_piparg *arg, char **envp, int size)
{
	int		fd[2];
	pid_t	pid;
	int		i;
	pid_t	*pdarr;

	i = 0;
	pdarr = (pid_t *)malloc(sizeof(pid_t) * size);
	if (!pdarr)
		return ;
	pipe(fd);
	pid = fork();
	while (pid && i < size - 1)
	{
		close(arg->inout[0]);
		close(fd[1]);
		arg->inout[0] = fd[0];
		pdarr[i] = pid;
		i++;
		pipe(fd);
		pid = fork();
	}
	close(fd[0]);
	if (!pid && i == size - 1)
		realex(arg, envp, i, arg->inout[1]);
	else if (!pid)
		realex(arg, envp, i, fd[1]);
	waiting(pdarr, pid, size);
}
