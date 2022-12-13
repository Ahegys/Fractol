/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:02:55 by afelipe-          #+#    #+#             */
/*   Updated: 2022/12/13 20:02:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractal.h"

void	init_j(t_data *mlx)
{
	mlx->julia.complex_x = 0;
	mlx->julia.complex_y = 0;
	mlx->julia.animation = 0;
}
void	phrases(void)
{
	ft_printf("\n==== Please enter a valid argument ====\n");
	ft_printf("|Fractals available:                  |\n");
	ft_printf("|- Mandelbrot                         |\n");
	ft_printf("|- Tricorn                            |\n");
	ft_printf("|- Julia [x] [y]                      |\n");
	ft_printf("=======================================\n");
	ft_printf ("\nJulia Fractal Instructions:\n");
	ft_printf("\n-Select values between -2 and 2 for the X and Y \n\
and form different sets of the fractol julia.\n");
	ft_printf("-Suggestion: 0.34  -0.05\n");
	ft_printf("-Suggestio: -0.835 -0.2321\n");
	ft_printf("-Suggestion: 0.285  0.01 \n\n\n");
}

char	*lower_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	char	*temp;
	t_data	mlx;

	init_j(&mlx);
	if (count_args(argc, argv, &mlx) != 0)
	{
		phrases();
		return (-1);
	}
	temp = lower_case(argv[1]);
	if (check_frac(temp, &mlx, argc) != 0)
	{
		phrases();
		return (-1);
	}
	return (0);
}
