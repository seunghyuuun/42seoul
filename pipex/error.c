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

void	autoerror(void)
{
	char	*str;

	str = strerror(errno);
	write(2, str, ft_strlen(str));
	exit(-1);
}

void	manualerror(char *str)
{
	if (ft_strncmp(str, "more argv\n", 100) == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strncmp(str, "alloc fail\n", 100) == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strncmp(str, "command not found\n", 100) == 0)
		write(2, str, ft_strlen(str));
	else if (ft_strncmp(str, "errno", 100) == 0)
		autoerror();
	exit(-1);
}
