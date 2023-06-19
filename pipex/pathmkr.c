/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathmkr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:12:12 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/19 12:14:52 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**envpath(char **envp)
{
	int		i;
	char	**result;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp("PATH=", envp[i], ft_strlen("PATH="))))
			break ;
		i++;
	}
	result = ft_split(envp[i] + ft_strlen("PATH="), ':');
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

char	*pathok(char **path, char *cmd)
{
	char	*result;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
	{
		result = ft_strdup(cmd);
		return (result);
	}
	result = 0;
	while (path[i])
	{
		result = ft_strjoin(path[i], cmd);
		if (access(result, X_OK) == 0)
			return (result);
		free(result);
		result = 0;
		i++;
	}
	return (result);
}

char	**pathmkr(char ***cmd, char **envp)
{
	char	**result;
	int		i;
	int		size;
	char	**path;

	size = 0;
	i = 0;
	path = envpath(envp);
	if (!path)
		return (0);
	while (cmd[size])
		size++;
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
	{
		twodfree(path);
		return (0);
	}
	result[size] = 0;
	while (i < size)
	{
		result[i] = pathok(path, cmd[i][0]);
		if (!result[i])
		{
			twodfree(result);
			result = 0;
			break ;
		}
		i++;
	}
	twodfree(path);
	return (result);
}
