/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plancheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:57:14 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/13 17:00:22 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	planerror(t_map *map, char *planline, int fd, char *message)
{
	free(planline);
	close(fd);
	errorend(map, message);
}

size_t	planlinecheck(char *planline, const char *components)
{
	size_t			i;
	static size_t	playercount;
	static size_t	exitcount;

	i = 0;
	if (!planline)
		return (0);
	while (planline[i] && planline[i] != '\n')
	{
		if (!(ft_strchr(components, planline[i])))
			return (0);
		else if (planline[i] == 'P')
			playercount++;
		else if (planline[i] == 'E')
			exitcount++;
		i++;
	}
	if (i < 3 || playercount > 1 || exitcount > 1)
		return (0);
	if (planline[0] != '1' || planline[i - 1] != '1')
		return (0);
	planline[i] = '\0';
	return (i);
}

void	plancheck(t_map *map, int fd)
{
	char	*temp;
	char	*planline;

	map->plan = get_next_line(fd);
	map->garo = planlinecheck(map->plan, "1");
	if (!map->garo)
		planerror(map, 0, fd, "Error\n: Wrong Map\n");
	map->sero = 1;
	planline = get_next_line(fd);
	while (planline)
	{
		if (map->garo != planlinecheck(planline, "01CEPX"))
			planerror(map, planline, fd, "Error\n: Wrong Map\n");
		temp = map->plan;
		map->plan = ft_strjoin(temp, planline);
		free(temp);
		free(planline);
		map->sero++;
		planline = get_next_line(fd);
	}
	close(fd);
	if (!map->plan)
		errorend(map, "Error\n: Malloc Fail\n");
	if (!(planlinecheck(&(map->plan[i2d(map, 0, map->sero - 1)]), "1")))
		errorend(map, "Error\n: Wrong Map\n");
}
