/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:51 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/14 13:18:19 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xbutton(t_map *map)
{
	map = 0;
	exit(0);
}

int	filecheck(char *mapname)
{
	char	*temp;
	int		fd;

	temp = ft_strrchr(mapname, '.');
	if (!temp || ft_strncmp(temp, ".ber", 5))
		undefinederror("Error\n: Use only .ber file\n");
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		definederror();
	return (fd);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		undefinederror("Error\n: standard form: ./so_long Map.ber\n");
	plancheck(&map, filecheck(argv[1]));
	pathcheck(&map);
	map.mlx = mlx_init();
	if (!(map.mlx))
		errorend(&map, ERR_PLAN, "Error\n: init fail\n");
	map.win = mlx_new_window(map.mlx, 32 * map.garo, 32 * map.sero, "so_long");
	if (!(map.win))
		errorend(&map, ERR_PLAN, "Error\n: new window fail\n");
	newimage(&map);
	planset(&map, map.mlx, map.win);
	mlx_key_hook(map.win, &key_hook, &map);
	mlx_hook(map.win, 17, 0, &xbutton, &map);
	mlx_loop(map.mlx);
	return (0);
}
