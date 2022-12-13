/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:14 by user              #+#    #+#             */
/*   Updated: 2022/12/13 18:27:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	cmp(const char *s1, const char *s2)
{
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 == *us2 && *us1 != '\0')
	{
		us1++;
		us2++;
	}
	return ((*us1 > *us2) - (*us1 < *us2));
}

int	count_args(int argc, char **argv, t_data *mlx)
{
	int	x;
	int	y;

	if (argc <= 1 || argc > 4 || argc == 3)
		return (-1);
	if (argc == 4)
	{
		mlx->julia.complex_y = ft_atof(argv[3], mlx);
		mlx->julia.complex_x = ft_atof(argv[2], mlx);
	}
	x = mlx->julia.complex_x;
	y = mlx->julia.complex_y;
	if ((x > 2 || x < -2) || (y > 2 || y < -2))
		return (-1);
	return (0);
}

int	check_frac(char *s1, t_data *mlx, int argc)
{
	char	*s2;

	s2 = NULL;
	if (s1[0] == 'm')
		s2 = set_flag(s1[0], mlx);
	else if (s1[0] == 't')
		s2 = set_flag(s1[0], mlx);
	else if (s1[0] == 'j')
	{
		if (argc == 2)
			return (-1);
		else
			s2 = set_flag(s1[0], mlx);
	}
	else
		return (-1);
	if (cmp(s1, s2) != 0)
		return (-1);
	else
		screen(mlx);
	return (0);
}

char	*set_flag(char c, t_data *mlx)
{
	char	*s2;

	s2 = NULL;
	if (c == 'm')
	{
		mlx->frac.flag = 'm';
		s2 = "mandelbrot";
	}
	else if (c == 't')
	{
		s2 = "tricorn";
		mlx->frac.flag = 't';
	}
	else if (c == 'j')
	{
		s2 = "julia";
		mlx->frac.flag = 'j';
	}
	return (s2);
}

double	ft_atof(const char *str, t_data *mlx)
{
	int	i;

	i = 0;
	mlx->atof.power = 1;
	mlx->atof.res = 0;
	mlx->atof.sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			mlx->atof.sign *= -1;
	while (ft_isdigit(str[i]))
		mlx->atof.res = str[i++] - '0' + mlx->atof.res * 10;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		mlx->atof.res = mlx->atof.res * 10 + str[i++] - '0';
		mlx->atof.power *= 10;
	}
	return (mlx->atof.sign * mlx->atof.res / mlx->atof.power);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}
