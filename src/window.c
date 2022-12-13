/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:37 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/13 13:23:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	screen(t_data *mlx)
{
	t_img	img;

	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fractal");
	event_caller(mlx, &img);
	free(mlx);
	return (1);
}

int	close_window(t_data *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img.img);
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_display(mlx->init);
	if (mlx->init)
		free(mlx->init);
	exit(0);
	return (1);
}

void	mandel_set(t_data *mlx)
{
	mlx->frac.min_r_num = -2.2;
	mlx->frac.max_r_num = 1.0;
	mlx->frac.min_i_num = -1.5;
	mlx->frac.max_i_num = (mlx->frac.max_r_num - mlx->frac.min_r_num) * HEIGHT
		/ WIDTH + mlx->frac.min_i_num;
	mlx->frac.max_inter = 100;
}
