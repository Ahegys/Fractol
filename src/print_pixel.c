/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:03:27 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/11 20:03:28 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	pixel(t_data *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->img.addr + (y * mlx->img.line_len + x * (mlx->img.bpp / 8));
	*(unsigned int *)dest = color;
}

int	background(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			pixel(mlx, j++, i, 0xFFFFFF);
		i++;
	}
	return (0);
}
