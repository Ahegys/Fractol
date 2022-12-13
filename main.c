/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:02:55 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/13 03:45:47 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractal.h"
int	msg()
{
	ft_printf("\x1b[38;5;196mInvalid Argument!\033[0m");
	return (1);
}

int main(int ac, char *av[])
{
	t_data mlx;
	
	if (ac < 2 || ac > 4)
		return (msg());
	else if (cmp("Mandelbrot", av[1]) == 0)
	{
		if (ac > 2)
			return (ft_printf("No parameter in Mandelbrot!"));
		screen(&mlx);
		ft_printf("\x1b[38;5;10m Mandelbrot run! \033[0m");
	}
	else if (cmp("Julia", av[1]) == 0)
	{
		if (ac != 4)
				return(ft_printf("few parameters in julia!"));
		screen(&mlx);
		ft_printf("\x1b[38;5;10m Julia run! \033[0m");
	}
	return(0);
}
