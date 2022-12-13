/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:50 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/13 20:30:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	set_fractal(int x, int y, double i, t_data *mlx)
{
	int	color;

	color = 265;
	if (i == mlx->frac.max_inter)
		color = 0xfefefefe;
	if (mlx->frac.color == 1)
		color =  i * color;
	if (mlx->frac.color == 2)
		color =  color * color;
	if (mlx->frac.color == 3)
		color = 222 * i * color;
	else
		color = 111 * i;
	pixel(mlx, x, y, color);
	return (1);
}

int	draw(t_data *mlx)
{
	double	x;
	double	y;
	double	inter;

	x = -1.0;
	while (x++ < WIDTH)
	{
		y = -1.0;
		while (y++ < HEIGHT)
		{
			if (mlx->frac.flag == 'm' || mlx->frac.flag == 't')
				inter = mandelbrot(r_num(x, mlx), i_num(y, mlx), mlx);
			else if (mlx->frac.flag == 'j')
				inter = julia(r_num(x, mlx), i_num(y, mlx), mlx);
			set_fractal(x, y, inter, mlx);
		}
	}
	return (2);
}
