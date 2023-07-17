/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:33 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/15 13:46:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	updateimage(t_map *map, size_t position, size_t future)
{
	size_t	g;
	size_t	s;

	s = (position / map->garo) * 32;
	g = (position % map->garo) * 32;
	mlx_put_image_to_window(map->mlx, map->win, map->empty, g, s);
	map->plan[position] = '0';
	s = (future / map->garo) * 32;
	g = (future % map->garo) * 32;
	if (map->pnum == 1)
	{
		map->pnum = 2;
		mlx_put_image_to_window(map->mlx, map->win, map->player2, g, s);
	}
	else
	{
		map->pnum = 1;
		mlx_put_image_to_window(map->mlx, map->win, map->player1, g, s);
	}
	map->plan[future] = 'P';
}

void	moving(t_map *map, size_t shift, int plus, unsigned int *movement)
{
	char	*position;
	char	*future;

	position = ft_strchr(map->plan, 'P');
	if (plus)
		future = position + shift;
	else
		future = position - shift;
	if (*future == '1' || (*future == 'E' && map->collection))
		return ;
	(*movement)++;
	ft_printf("%u\n", *movement);
	if (*future == 'C')
		(map->collection)--;
	if (*future == 'X' || *future == 'E')
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
		exit (0);
	}
	updateimage(map, position - map->plan, future - map->plan);
}

int	key_hook(int keycode, t_map *map)
{
	static unsigned int	movement;

	if (keycode == ESC_KEY)
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
		exit (0);
	}
	if (keycode == W_KEY)
		moving(map, map->garo, 0, &movement);
	else if (keycode == A_KEY)
		moving(map, 1, 0, &movement);
	else if (keycode == S_KEY)
		moving(map, map->garo, 1, &movement);
	else if (keycode == D_KEY)
		moving(map, 1, 1, &movement);
	return (0);
}
