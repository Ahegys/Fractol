/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:14:35 by user              #+#    #+#             */
/*   Updated: 2022/12/13 15:14:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

float	burnship(double num_r, double num_i, t_data *prop)
{
	double	x;
	double	y;
	double	inter;
	double	cache;

	x = 0;
	y = 0;
	inter = 0;
	while (inter < prop->frac.max_inter)
	{
		cache = x * x - y * y + num_r;
		y = abst(2 * x * y) + num_i;
		x = cache;
		if (x * x + y * y > 4.0)
			return (inter);
		inter++;
	}
	return (inter);
}
