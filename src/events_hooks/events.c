#include "../../includes/fractal.h"
int		render(t_data *mlx)
{
	draw(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.img, 0, 0);
	return (1);
}


int	key_hook(int key_code, t_data *mlx)
{
	if (key_code == 'z')
		mlx->frac.max_inter = mlx->frac.max_inter + 10;
	if (key_code == 'x')
		mlx->frac.max_inter = mlx->frac.max_inter - 10;
	if (key_code == ESC)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		mlx_destroy_display(mlx->init);
		if (mlx->init)
			free(mlx->init);
		exit(0);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *mlx)
{
	printf("MouseBtn >> %i\nPosX >> %i\nPosY >> %i\n", button, x, y);
	if (button == 4)
	{
		mlx->frac.max_r_num = mlx->frac.max_r_num - 0.1;
		mlx->frac.min_r_num = mlx->frac.min_r_num + 0.05;
		mlx->frac.min_i_num = mlx->frac.min_i_num + 0.05;
		mlx->frac.max_i_num = mlx->frac.max_i_num - 0.1;
	}
	if (button == 5)
	{
		mlx->frac.max_r_num = mlx->frac.max_r_num + 0.1;
		mlx->frac.min_r_num = mlx->frac.min_r_num - 0.05;
		mlx->frac.min_i_num = mlx->frac.min_i_num - 0.05;
		mlx->frac.max_i_num = mlx->frac.max_i_num + 0.1;
	}
/*	if (button == 2)
		mlx->frac.max_r_num = mlx->frac.max_r_num - 0.05;
	if (button == 1)
		mlx->frac.max_r_num = mlx->frac.max_r_num + 0.05;
	if (button == 4)
		mlx->frac.min_i_num = mlx->frac.min_i_num - 0.05;
	if (button == 5)
		mlx->frac.min_i_num = mlx->frac.min_i_num + 0.05;
	if (button == 6)
		mlx->frac.min_r_num = mlx->frac.min_r_num - 0.05;
	if (button == 7)
		mlx->frac.min_r_num = mlx->frac.min_r_num + 0.05; */
	return (0);
}

int	event_caller(t_data *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->init, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	mlx->img = *img;
	mandel_set(mlx);
	mlx_mouse_hook(mlx->win, &mouse_hook, mlx);
	mlx_loop_hook(mlx->init, &render, mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_loop(mlx->init);
	return (0);
}

void	mandel_set(t_data *mlx)
{
	mlx->frac.min_r_num = -2.2; //modifica o posicionamento dele (Menor valor vai para a esquerda maior para a direita)
	mlx->frac.max_r_num = 3.0; //modifica a escala do seu fractol (menor valor aproxima e maior valor diminui a escala)
	mlx->frac.min_i_num = -1.8; //modifica a altura em que se encontra (menor valor para cima maior valor para baixo)
	mlx->frac.max_i_num = (mlx->frac.max_r_num - mlx->frac.min_r_num)
			* HEIGHT / WIDTH + mlx->frac.min_i_num; // essa conta faz com que as posiçoes funcionem de forma correta, alterar o valor devera altera as posições do fractal
	mlx->frac.max_inter = 100;// nivel de detalhamento do fractol (quanto mais proximo do 100 mais detalhes, porem menos desempenho, quando menor, menos detalhes porem mais desempenhos)
}

