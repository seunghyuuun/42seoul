/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:57:42 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/12 20:38:44 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	i2d(t_map *map, size_t g, size_t s)
{
	return (g + s * map->garo);
}

void	newimage(t_map *map)
{
	int	w;
	int	h;

	map->empty = mlx_xpm_file_to_image(map->mlx, "textures/empty.xpm", &w, &h);
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &w, &h);
	map->player1 = mlx_xpm_file_to_image(map->mlx, "textures/32w.xpm", &w, &h);
	map->player2 = mlx_xpm_file_to_image(map->mlx, "textures/34w.xpm", &w, &h);
	map->enemy = mlx_xpm_file_to_image(map->mlx, "textures/enemy.xpm", &w, &h);
	map->collect = mlx_xpm_file_to_image(map->mlx, "textures/item.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &w, &h);
	map->pnum = 1;
}

void	planset(t_map *map)
{
	size_t	g;
	size_t	s;

	newimage(map);
	s = 0;
	while (s < map->sero)
	{
		g = 0;
		while (g < map->garo)
		{
			if (map->plan[i2d(map, g, s)] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->wall, 32 * g, 32 * s);
			else if (map->plan[i2d(map, g, s)] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->exit, 32 * g, 32 * s);
			else
				mlx_put_image_to_window(map->mlx, map->win, map->empty, 32 * g, 32 * s);
			if (map->plan[i2d(map, g, s)] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->player1, 32 * g, 32 * s);
			else if (map->plan[i2d(map, g, s)] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->collect, 32 * g, 32 * s);
			else if (map->plan[i2d(map, g, s)] == 'X')
				mlx_put_image_to_window(map->mlx, map->win, map->enemy, 32 * g, 32 * s);
			g++;
		}
		s++;
	}
}
