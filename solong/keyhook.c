/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:33 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/12 21:03:24 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	updateimage(t_map *map, size_t position, size_t future)
{
	size_t	g;
	size_t	s;

	s = position / map->garo;
	g = position % map->garo;
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->empty, 32 * g, 32 * s);
	map->plan[position] = '0';
	s = future / map->garo;
	g = future % map->garo;
	if (map->pnum == 1)
	{
		map->pnum = 2;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player2, 32 * g, 32 * s);
	}
	else
	{
		map->pnum = 1;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player1, 32 * g, 32 * s);
	}
	map->plan[future] = 'P';
}

void	moving(t_map *map, size_t shift, int plus, unsigned int *movement)
{
	char	*position;
	char	*future;
	//char	*temp;

	position = ft_strchr(map->plan, 'P');
	if (plus)
		future = position + shift;
	else
		future = position - shift;
	if (*future == '1')
		return ;
	(*movement)++;
	//temp = ft_itoa((int)(*movement));
	//mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 32 * (map->sero), 15, temp);
	//free(temp);
	ft_printf("%u\n", *movement);
	if (*future == 'X' || *future == 'E')
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit (0);
	}
	updateimage(map, position - map->plan, future - map->plan);
}

int	key_hook(int keycode, t_map *map)
{
	static unsigned int	movement;

	if (keycode == ESC_KEY)
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
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
