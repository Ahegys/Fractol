#include "../includes/fractal.h"
float		r_num(double x, t_data *prop)
{
	double	range;

	range = prop->frac.max_r_num - prop->frac.min_r_num;
	return (prop->frac.min_r_num + (x *  range) / WIDTH);
}

float		i_num(double y, t_data *prop)
{
	double	range;

	range = prop->frac.max_i_num - prop->frac.min_i_num;
	return (prop->frac.min_i_num + (y *  range) / HEIGHT);
}

int		mandelbrot(double num_r, double num_i, t_data *prop)
{
	double	x;
	double	y;
	double	inter;
	double	cache;
	
	x = 0;
	y = 0;
	inter = 0;
	while (inter < prop->frac.max_inter)
	{
		cache = x * x - y * y + num_r; // subtrair com o num_r o fractol espelha
		y = 2 * x * y + num_i; //valor de (2) padrão sera de mandelbrot trocando o valor de 2 pra x, vira outro fractol, colocando o -2 vira outro, altere quanto quiser pra achar formas novas
		x = cache;
		if (x * x + y * y > 4.0) // quando essa conta for maior que o numero posto ele tende ao infinito, ele aumenta o tamanho do fractal
				return (inter);
		inter++;
	};
	return (inter);
}

int		julia(double num_r, double num_i, t_data *prop)
{
	double	x;
	double	y;
	double	inter;
	double	cache;
	
	x = num_r;
	y = num_i;
	inter = 0;
	while (inter < prop->frac.max_inter)
	{
		cache = x * x - y * y + -0.4;
		y = 2 * x * y - 0.6; 
		x = cache;
		if (x * x + y * y > 4.0)
				return (inter);
		inter++;
	};
	return (inter);
}
