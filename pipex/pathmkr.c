/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathmkr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:12:12 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/26 13:07:20 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	erasepath(char **path, char **cmdpath, t_piparg *arg, char *str)
{
	if (path)
		twodfree(path);
	if (cmdpath)
		twodfree(cmdpath);
	threedfree(arg->cmd);
	manualerror(str);
}

char	**envextract(char **envp)
{
	int		i;
	char	**result;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp("PATH=", envp[i], ft_strlen("PATH="))))
			break ;
		i++;
	}
	result = ft_split(envp[i] + ft_strlen("PATH="), ':');
	return (result);
}

char	**envpath(char **envp)
{
	int		i;
	char	**result;
	char	*temp;

	result = envextract(envp);
	if (!result)
		return (0);
	i = 0;
	while (result[i])
	{
		temp = result[i];
		result[i] = ft_strjoin(temp, "/");
		free(temp);
		if (!result[i])
		{
			twodfree(result);
			return (0);
		}
		i++;
	}
	return (result);
}

void	pathok(char **path, t_piparg *arg, char **result, int index)
{
	int		i;
	char	*ccmd;

	i = 0;
	ccmd = arg->cmd[index][0];
	result[index] = 0;
	while (path[i])
	{
		result[index] = ft_strjoin(path[i], ccmd);
		if (!result[index])
			erasepath(path, result, arg, "pipex: alloc fail\n");
		else if (access(result[index], X_OK) == 0)
			return ;
		free(result[index]);
		result[index] = 0;
		i++;
	}
	if (!result[index])
		erasepath(path, result, arg, "pipex: command not found\n");
}

char	**pathmkr(t_piparg *arg, char **envp)
{
	char	**result;
	int		i;
	int		size;
	char	**path;

	size = 0;
	i = 0;
	path = envpath(envp);
	if (!path)
		erasepath(0, 0, arg, "pipex: alloc fail\n");
	while (arg->cmd[size])
		size++;
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		erasepath(path, 0, arg, "pipex: alloc fail\n");
	result[size] = 0;
	while (i < size)
	{
		pathok(path, arg, result, i);
		if (!result[i])
			erasepath(path, result, arg, "pipex: alloc fail\n");
		i++;
	}
	twodfree(path);
	return (result);
}
