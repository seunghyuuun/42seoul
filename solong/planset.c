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

void	newimage(t_map *map)
{
	int	width;
	int	height;

	map->empty = mlx_xpm_file_to_image(map->mlx_ptr, "textures/empty.xpm", &width, &height);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, "textures/wall.xpm", &width, &height);
	map->player1 = mlx_xpm_file_to_image(map->mlx_ptr, "textures/32walk32.xpm", &width, &height);
	map->player2 = mlx_xpm_file_to_image(map->mlx_ptr, "textures/32walk34.xpm", &width, &height);
	map->enemy = mlx_xpm_file_to_image(map->mlx_ptr, "textures/enemy.xpm", &width, &height);
	map->collect = mlx_xpm_file_to_image(map->mlx_ptr, "textures/item.xpm", &width, &height);
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr, "textures/exit.xpm", &width, &height);
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
			if (map->plan[g + s * map->garo] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall, 32 * g, 32 * s);
			else if (map->plan[g + s * map->garo] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->exit, 32 * g, 32 * s);
			else
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->empty, 32 * g, 32 * s);
			if (map->plan[g + s * map->garo] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player1, 32 * g, 32 * s);
			else if (map->plan[g + s * map->garo] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->collect, 32 * g, 32 * s);
			else if (map->plan[g + s * map->garo] == 'X')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->enemy, 32 * g, 32 * s);
			g++;
		}
		s++;
	}
}
