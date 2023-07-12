/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plancheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:57:14 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/12 20:36:45 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bercheck(char *mapname)
{
	char	*temp;

	temp = ft_strrchr(mapname, '.');
	if (!temp || ft_strncmp(temp, ".ber", 5))
		undefinederror("Error\n: Use only .ber file\n");
}

int	planlinecheck(char *planline)
{
	size_t	i;

	i = 0;
	while (planline[i] && planline[i] != '\n')
	{
		if (!(ft_strchr("01CEPX", planline[i])))
			return (0);
		i++;
	}
	if (!planline[i])
		return (0);
	planline[i] = '\0';
	return (1);
}

void	plancheck(t_map *map, char *mapname)
{
	int		fd;
	char	*temp;
	char	*planline;

	bercheck(mapname); /*main문에서 해도 됨*/
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		definederror();
	map->plan = get_next_line(fd);
	if (!(planlinecheck(map->plan)))
		errorend(map, ERR_PLAN, "Error\n: Wrong Map\n");
	map->garo = ft_strlen(map->plan);
	map->sero = 1;
	planline = get_next_line(fd);
	while (planline)
	{
		if (!(planlinecheck(planline)) || map->garo != ft_strlen(planline))
			errorend(map, ERR_PLAN, "Error\n: Wrong Map\n");
		temp = map->plan;
		map->plan = ft_strjoin(temp, planline);
		free(temp);
		free(planline);
		map->sero++;
		planline = get_next_line(fd);
	}
	close(fd);
    //P E가 하나인지, 벽으로 둘러쌓여있는지, 유효한 경로가 있는지
}
