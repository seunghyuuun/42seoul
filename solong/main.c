/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:51 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/12 21:04:47 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xbutton(t_map *map)
{
	map = 0;
	ft_printf("end\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		undefinederror("Error\n: standard form: ./so_long Map.ber\n");
	plancheck(&map, argv[1]);
	map.mlx_ptr = mlx_init();
	if (!(map.mlx_ptr))
		errorend(&map, ERR_PLAN, "Error\n: init fail\n");
	map.win_ptr = mlx_new_window(map.mlx_ptr, 32 * map.garo, 32 * map.sero, "so_long");
	if (!(map.win_ptr))
		errorend(&map, ERR_PLAN, "Error\n: new window fail\n");
	planset(&map);
	mlx_key_hook(map.win_ptr, &key_hook, &map);
	mlx_hook(map.win_ptr, 17, 0, &xbutton, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
