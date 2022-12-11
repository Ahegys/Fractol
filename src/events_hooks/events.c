/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:15 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/11 20:03:15 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"
int		render(t_data *mlx)
{
	draw(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.img, 0, 0);
	return (1);
}

int		tracker(int x, int y, t_data *mlx)
{
	mlx->pos.x = r_num(x, mlx);
	mlx->pos.y = i_num(y, mlx);
	return (1);
}
int	key_hook(int key_code, t_data *mlx)
{
	if (key_code == 'z')
		mlx->frac.max_inter = mlx->frac.max_inter + 10;
	if (key_code == 'x')
		mlx->frac.max_inter = mlx->frac.max_inter - 10;
	if (key_code == ESC)
	{
		close_window(mlx);
	}
		if (key_code == 'r')
			mandel_set(mlx);
		if (key_code == '1')
			mlx->selection = 1;
		else
			mlx->selection = 0;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *mlx)
{
	printf("%i\n, %i\n", x, y);
	if (button == 4)
	{
		mlx->frac.max_r_num -= mlx->frac.max_r_num * 0.115;
		mlx->frac.min_r_num -= mlx->frac.min_r_num * 0.115;
		mlx->frac.min_i_num -= mlx->frac.min_i_num * 0.115;
		mlx->frac.max_i_num -= mlx->frac.max_i_num * 0.115;
	}
	if (button == 5)
	{
		mlx->frac.max_r_num += mlx->frac.max_r_num * 0.155;
		mlx->frac.min_r_num += mlx->frac.min_r_num * 0.155;
		mlx->frac.min_i_num += mlx->frac.min_i_num * 0.155;
		mlx->frac.max_i_num += mlx->frac.max_i_num * 0.155;
	}
	return (0);
}

int	event_caller(t_data *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->init, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	mlx->img = *img;
	mandel_set(mlx);
	mlx_hook(mlx->win, 6, 1L << 6, tracker, mlx);
	mlx_mouse_hook(mlx->win, &mouse_hook, mlx);
	mlx_loop_hook(mlx->init, &render, mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_loop(mlx->init);
	return (0);
}

void	mandel_set(t_data *mlx)
{
	mlx->frac.min_r_num = -2.2;
	mlx->frac.max_r_num =1.0; 
	mlx->frac.min_i_num = -1.5;
	mlx->frac.max_i_num = (mlx->frac.max_r_num - mlx->frac.min_r_num)
			* HEIGHT / WIDTH + mlx->frac.min_i_num;
	mlx->frac.max_inter = 100;
}
