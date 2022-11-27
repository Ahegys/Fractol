#include "../includes/fractal.h"

void	pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

int	background(t_data *mlx, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			pixel(img, j++, i, 0xfcba03);
		i++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, img->img, 0, 0);
	return (0);
}
