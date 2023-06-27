/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmpfile_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:42:16 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/27 17:17:07 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*nonexitpath(void)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("./A");
	i = 2;
	while (result && !access(result, F_OK))
	{
		result[i]++;
		if (result[i] == 'z')
		{
			while (result[i] == 'z')
				result[i++] = 'A';
			if (!result[i])
			{
				temp = result;
				result = ft_strjoin(temp, "A");
				free(temp);
			}
			else
				result[i]++;
			i = 2;
		}
	}
	return (result);
}

int	notendline(char *line, char *endline)
{
	size_t	newlinepoint;

	newlinepoint = ft_strlen(endline);
	if (ft_strncmp(line, endline, newlinepoint))
		return (1);
	else if (line[newlinepoint] != '\n')
		return (1);
	return (0);
}

int	tmpfilemaker(char *endline, char *filepath)
{
	int			fd;
	char		*line;

	fd = open(filepath, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (fd);
	line = get_next_line(0);
	while (notendline(line, endline))
	{
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd);
	return (open(filepath, O_RDONLY));
}

int	makeorclose(char *endline, int fd)
{
	static char	*filepath;

	if (!endline)
	{
		if (filepath)
		{
			if (unlink(filepath) == -1)
				manualerror("errno");
			free(filepath);
			filepath = 0;
		}
		else if (fd)
			close(fd);
		return (0);
	}
	filepath = nonexitpath();
	return (tmpfilemaker(endline, filepath));
}	
