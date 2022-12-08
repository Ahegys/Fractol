#ifndef FRACTOL_H
# define FRACTOL_H
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
# define WIDTH 700
# define HEIGHT 700

// ===================== MACROS

# define ESC 65307

typedef	struct l_mouse
{
	int	x;
	int	y;
}				t_mouse;

typedef struct l_props
{
	double	min_r_num;
	double	max_r_num;
	double	min_i_num;
	double	max_i_num;
	double	max_inter;
	double		min_inter;
	int		fractol;
}				t_props;

typedef struct l_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
} t_img;

typedef	struct l_data
{
	void	*init;
	void	*win;
	t_img	img;
	t_props	frac;
	t_mouse	pos;
}				t_data;

void	mandel_set(t_data *mlx);
int		screen(t_data *mlx);
int     key_hook(int key_code, t_data *mlx);
int		mandelbrot(double num_r, double num_i, t_data *prop);
float	i_num(double y, t_data *prop);
int		set_fractal(int x, int y, int i, t_data *mlx);
int		draw(t_data *mlx);
int		background(t_data *mlx);
int		event_caller(t_data *mlx, t_img *img);
void	pixel(t_data *mlx, int x, int y, int color);
int		mouse_hook(int button, int x, int y, t_data *mlx);
int		potency(int number, int power);
float	r_num(double x, t_data *prop);
#endif // FRACTOL_H

