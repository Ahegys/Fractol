#include "../../includes/fractal.h"
#include <stdio.h>

int	key_hook(int key_code, t_data *mlx)
{
	if (key_code == ESC)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		mlx_destroy_display(mlx->init);
		if (mlx->init)
			free(mlx->init);
		exit(0);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("MouseBtn >> %i\nPosX >> %i\nPosY >> %i\n", button, x, y);
	return (0);
}

int	event_caller(t_data *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->init, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	//mlx_loop_hook(mlx->init, render, img);
	mlx_mouse_hook(mlx->win, &mouse_hook, mlx);
	background(mlx, img);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_loop(mlx->init);
	return (0);
}

