/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:03 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/13 20:11:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700

// ===================== MACROS

# define ESC 65307

typedef struct l_mouse
{
	double	x;
	double	y;
}			t_mouse;

typedef struct l_props
{
	double	min_r_num;
	double	max_r_num;
	double	min_i_num;
	double	max_i_num;
	double	max_inter;
	double	min_inter;
	int		color2;
	int		color;
	char	flag;
}			t_props;

typedef struct l_atof
{
	int		i;
	int		sign;
	double	res;
	double	power;
}			t_atof;

typedef struct l_julia
{
	double	complex_x;
	double	complex_y;
	double	animation;
}			t_julia;

typedef struct l_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct l_data
{
	void	*init;
	void	*win;
	t_img	img;
	double	x;
	double	im;
	double	re_num;
	double	im_num;
	t_props	frac;
	t_mouse	pos;
	t_julia	julia;
	t_atof	atof;

}			t_data;

void		mandel_set(t_data *mlx);
int			screen(t_data *mlx);
int			key_hook(int key_code, t_data *mlx);
float		mandelbrot(double num_r, double num_i, t_data *prop);
char		*set_flag(char c, t_data *mlx);
double		float_conv(const char *str);
double		i_num(int y, t_data *f);
int			set_fractal(int x, int y, double i, t_data *mlx);
double		abst(double x);
int			ft_isdigit(int c);
double		ft_atof(const char *str, t_data *mlx);
int		check_frac(char *s1, t_data *mlx, int argc);
int			doubles(const char *str);
int			cmp(const char *s1, const char *s2);
int			close_window(t_data *mlx);
int			draw(t_data *mlx);
int			background(t_data *mlx);
int		count_args(int argc, char **argv, t_data *mlx);
int			event_caller(t_data *mlx, t_img *img);
void		pixel(t_data *mlx, int x, int y, int color);
int			mouse_hook(int button, int x, int y, t_data *mlx);
int			potency(int number, int power);
float		burnship(double num_r, double num_i, t_data *prop);
double		r_num(int x, t_data *f);
float		julia(double num_r, double num_i, t_data *prop);
#endif // FRACTOL_H
