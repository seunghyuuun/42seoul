/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdmkr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:10:24 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/22 15:22:57 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***cmdmkr(int argc, char **argv)
{
	char	***result;
	int		i;

	result = (char ***)malloc(sizeof(char **) * (argc - 3 + 1));
	if (!result)
		manualerror("alloc fail\n");
	result[argc - 3] = (char **)0;
	i = 0;
	while (i < argc - 3)
	{
		result[i] = ft_split(argv[i + 2], ' ');
		if (!result[i])
		{
			threedfree(result);
			manualerror("alloc fail\n");
		}
		i++;
	}
	return (result);
}
