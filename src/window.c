/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:37 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/12 16:38:53 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	screen(t_data *mlx)
{
	t_img	img;

	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fractal");
	
	event_caller(mlx, &img);
	return(1);

}

int	close_window(t_data *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_display(mlx->init);
	if (mlx->init)
		free(mlx->init);
	exit(0);
	return (1);
}

int cmp(const char *s1, const char *s2)
{

	const unsigned char *us1;
	const unsigned char *us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 == *us2 && *us1 != '\0')
	{
    	us1++;
    	us2++;
	}
	return (*us1 > *us2) - (*us1 < *us2);
}
