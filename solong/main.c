/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:51 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/11 16:38:17 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		undefinederror("Error\n: standard form: ./so_long Map.ber\n");
	plancheck(&map, argv[1]);
	map.mlx_ptr = mlx_init();
	if (!(map.mlx_ptr))
		errorend(map, ERR_PLAN, "Error\n: init fail\n");
	map.win_ptr = mlx_new_window(map.mlx_ptr, 64 * map.garo, 64 * map.sero);
	if (!(map.win_ptr))
		errorend(map, ERR_PLAN, "Error\n: new window fail\n");
	return (0);
}
