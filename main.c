/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:02:55 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/12 21:34:29 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractal.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	t_data mlx;
	
	if (ac < 2)
	{
		ft_printf("Please select fractal:\n");
		ft_printf("[name] = Mandelbrot.\n[name] == Julia [x], [im]\n");
		ft_printf("[name] = burnship\n");
		return (1);
	}
	if (ac > 4)
		return (ft_printf("Arguments [name], if its Julia = [x], [im]", av[1]));
	if (cmp("Julia", av[1]) == 0)
	{
		ft_printf("Julia Started\n");
		screen(&mlx);
	}
	if (cmp("Mandelbrot", av[1]) == 0)
	{
		ft_printf("Mandelbrot Started\n");
		screen(&mlx);
	}
	return(0);
}
