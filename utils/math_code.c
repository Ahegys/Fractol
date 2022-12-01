#include "../includes/fractal.h"

double		r_num(int x, t_data *prop)
{
	return (prop->frac.min_r_num + 
			(x * prop->frac.max_r_num - prop->frac.min_r_num) / WIDTH);
}

double		i_num(int y, t_data *prop)
{
	return (prop->frac.min_i_num + 
			(y * prop->frac.max_i_num - prop->frac.min_i_num) / HEIGHT);
}

double		mandelbrot(double num_r, double num_i, t_data *prop)
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
		if (x * x + y + y > 4)
				return (inter);
		inter++;
	};
	return (inter);
}

int		potency(int number, int power)
{
	int	i;
	int	n;
	
	i = 0;
	n = 1;
	while (i < power)
	{
		n *= number;
		i++;
	}
	return (n);
}

