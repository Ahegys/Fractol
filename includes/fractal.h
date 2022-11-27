#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

# define WIDTH 400
# define HEIGHT 400

// ===================== MACROS

# define ESC 65307



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
}				t_data;

int		screen(t_data *mlx);
int     key_hook(int key_code, t_data *mlx);
int     event_caller();
int		background(t_data *mlx, t_img *img);
void	pixel(t_img *img, int x, int y, int color);
int		mouse_hook(int button, int x, int y);
int		potency(int number, int power);
#endif // FRACTOL_H

