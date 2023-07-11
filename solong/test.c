#include "test/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_param;

typedef struct s_data
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	int		width;
	int		height;
}	t_data;

int	key_hook(int keycode, t_param *param)
{
	if (keycode == 53)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit (0);
	}
	return (printf("%d\n", keycode));
}

void	tileset(t_data *back, t_data *tile, int garo, int sero)
{
	int i;
	int j;
	int	g;
	int	s;

	
	s = 0;
	while (s < sero)
	{
		g = 0;
		while (g < garo)
		{
			j = 0;
			while (j < 64)
			{
				i = 0;
				while (i < 8 * back->bits_per_pixel)
				{
					back->addr[s * (back->size_line) * 64 + g * (8 * back->bits_per_pixel) \
					+ i + j * back->size_line] = tile->addr[i + j * tile->size_line];
					i++;
				}
				j++;
			}
			g++;
		}
		s++;
	}
}

int	main(void)
{
	t_param	param;
	t_data	tile;
	t_data	back;
	int		i;
	int		j;
	int		garo;
	int		sero;

	garo = 8;
	sero = 3;
	param.mlx_ptr = mlx_init();
	if (!param.mlx_ptr)
	{
		printf("init fail\n");
		return (-1);
	}
	param.win_ptr = mlx_new_window(param.mlx_ptr, 64 * garo, 64 * sero, "hello");
	if (!param.win_ptr)
	{
		printf("new window fail\n");
		return (-1);
	}
	tile.img_ptr = mlx_png_file_to_image(param.mlx_ptr, "tiles_free.png", &tile.width, &tile.height);
	back.img_ptr = mlx_new_image(param.mlx_ptr, 64 * garo, 64 * sero);
	tile.addr = mlx_get_data_addr(tile.img_ptr, &tile.bits_per_pixel, &tile.size_line, &tile.endian);
	back.addr = mlx_get_data_addr(back.img_ptr, &back.bits_per_pixel, &back.size_line, &back.endian);
	tileset(&back, &tile, garo, sero);
	mlx_destroy_image(param.mlx_ptr, tile.img_ptr);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, back.img_ptr, 0, 0);
	mlx_key_hook(param.win_ptr, &key_hook, &param);
	mlx_loop(param.mlx_ptr);
	//mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
