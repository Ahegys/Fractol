/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:18:00 by afelipe-          #+#    #+#             */
/*   Updated: 2022/10/10 16:29:44 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_digit(unsigned long num, int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		num /= base;
		count++;
	}
	return (count);
}

void	ft_putnbr(unsigned long num, char *n)
{
	size_t	len_base;

	len_base = ft_strlen(n);
	if (num / len_base > 0)
		ft_putnbr(num / len_base, n);
	ft_putchar(n[num % len_base]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_prefixs(const char *format, int len, va_list arg)
{
	char	str;
	char	*prefix;

	prefix = "%csdipuxX";
	str = *format;
	if (str == prefix[0] || str == prefix[1])
		len = p_char(format, len, arg);
	else if (str == prefix[2] || str == prefix[3] || str == prefix[4])
		len = p_stdi(format, len, arg);
	else if (str == prefix[5])
		len = p_ptr(format, len, arg);
	else if (str == prefix[6] || str == prefix[7] || str == prefix[8])
		len = p_ux(format, len, arg);
	else
		len = 0;
	return (len);
}
