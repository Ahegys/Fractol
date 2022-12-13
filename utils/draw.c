/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:50 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/12 19:00:37 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	set_fractal(int x, int y, int i, t_data *mlx)
{
	int	color;
	color =  265; //rosa
	if (i == mlx->frac.max_inter)
		color = 0xfefefe;
	else
		color =  i * color;
	pixel(mlx, x, y, color);	

	return (1);
}
// função draw onde ira desenhar o algoritimo
int	draw(t_data *mlx)
{
	double x;
	double y;
	double		inter;

	x = -1.0;
	while (x++ < WIDTH)
	{
			y = -1.0;
			while (y++ < HEIGHT)
			{
				if (mlx->selection == 1)
					inter = julia(r_num(x, mlx), i_num(y, mlx), mlx);
				else
					inter = mandelbrot(r_num(x, mlx), i_num(y, mlx), mlx);
				set_fractal(x, y, inter, mlx);
			}
	}
	return (2);
}
