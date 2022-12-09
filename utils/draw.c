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

	x = -1;
	while (x++ < WIDTH)
	{
			y = -1;
			while (y++ < HEIGHT)
			{
				if (mlx->selection == 1)
					inter = julia(r_num(x, mlx), i_num(y, mlx), mlx); //sem isso e so um pixel
				else
					inter = mandelbrot(r_num(x, mlx), i_num(y, mlx), mlx); //sem isso e so um pixel
				set_fractal(x, y, inter, mlx);
			}
	}
	return (2);
}
