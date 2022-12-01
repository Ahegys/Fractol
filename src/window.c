#include "../includes/fractal.h"
#include <stdlib.h>

int	screen(t_data *mlx)
{
	t_img	img;

	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fractal");
	
	event_caller(mlx, &img);
	return(1);

}

