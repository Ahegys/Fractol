#include "../includes/fractal.h"

double		abst(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
double	r_num(int x, t_data *f)
{
	double	range;

	range = f->frac.max_r_num - f->frac.min_r_num;
	return (f->frac.min_r_num + (x * range) / WIDTH);
}
double	i_num(int y, t_data *f)
{
	double	range;

	range = f->frac.max_i_num - f->frac.min_i_num;
	return (f->frac.min_i_num + (y * range) / HEIGHT);
}

float	burnship(double num_r, double num_i, t_data *prop)
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
		cache = x * x - y * y + num_r;
		y = abst(2 * x * y) + num_i;
		x = cache;
		if (x * x + y * y > 4.0)
				return (inter);
		inter++;
	};
	return (inter);
}


float		mandelbrot(double num_r, double num_i, t_data *prop)
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
		cache = x * x - y * y + num_r;
		y = 2 * x * y + num_i;
		x = cache;
		if (x * x + y * y > 4.0)
				return (inter);
		inter++;
	};
	return (inter);
}

float		julia(double num_r, double num_i, t_data *prop)
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
		cache = x * x - y * y + prop->pos.x;
		y = 2 * x * y - prop->pos.y; 
		x = cache;
		if (x * x + y * y > 4.0)
				return (inter);
		inter++;
	};
	return (inter);
}
