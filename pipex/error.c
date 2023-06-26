/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:34:38 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/26 15:48:09 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (ft_strncmp(s1, s2, len1));
	else
		return (ft_strncmp(s1, s2, len2));
}

void	autoerror(void)
{
	perror("pipex");
	exit(127);
}

void	manualerror(char *str)
{
	if (ft_strcmp(str, "pipex: more argv\n") == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strcmp(str, "pipex: alloc fail\n") == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strcmp(str, "pipex: command not found\n") == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strcmp(str, "errno") == 0)
		autoerror();
	exit(127);
}
