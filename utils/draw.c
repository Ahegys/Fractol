#include "../includes/fractal.h"

int	set_fractal(int x, int y, int i, t_data *mlx)
{
	int	color;

	color = 0xf50a0a;
	if (i == mlx->frac.max_inter)
		color = 0xfefefe;
	else 
		color = i * 102111255;
	pixel(mlx, x, y, color);	

	return (1);
}

int	draw(t_data *mlx)
{
	double x;
	double y;
	int		inter;

	x = -1;
	while (x++ < WIDTH)
	{
			y = -1;
			while (y++ < HEIGHT)
			{
				inter = mandelbrot(r_num(x, mlx), i_num(y, mlx), mlx);
				set_fractal(x, y, inter, mlx);
			}
	}
	return (2);
}
