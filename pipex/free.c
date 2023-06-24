/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:10:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/22 15:23:26 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	twodfree(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	threedfree(char ***s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		twodfree(s[i]);
		i++;
	}
	free(s);
}

void	erasearg(t_piparg *arg, char *str)
{
	threedfree(arg->cmd);
	twodfree(arg->cmdpath);
	manualerror(str);
}
