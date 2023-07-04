/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdmkr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:20:15 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/04 19:57:33 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmdempty(char *str, char ***result, int i)
{
	int	index;

	index = 0;
	while (str[index] == ' ')
		index++;
	if (!(str[index]))
	{
		result[i] = 0;
		threedfree(result);
		manualerror("pipex: command not found\n");
	}
}

char	***bs_cmdmkr(int argc, char **argv, int skip)
{
	char	***result;
	int		i;

	result = (char ***)malloc(sizeof(char **) * (argc - skip));
	if (!result)
		manualerror("pipex: alloc fail\n");
	result[argc - skip - 1] = (char **)0;
	i = 0;
	while (i < argc - (skip + 1))
	{
		cmdempty(argv[i + skip], result, i);
		result[i] = ft_split(argv[i + skip], ' ');
		if (!result[i])
		{
			threedfree(result);
			manualerror("pipex: alloc fail\n");
		}
		i++;
	}
	return (result);
}
