/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:17:21 by afelipe-          #+#    #+#             */
/*   Updated: 2022/10/10 19:32:14 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_char(const char *format, int len, va_list arg)
{
	int		i;
	char	*key;

	key = "c%";
	if (*format == key[1])
	{
		ft_putchar(key[1]);
		len++;
	}
	else if (*format == key[0])
	{
		i = va_arg(arg, int);
		ft_putchar(i);
		len++;
	}
	return (len);
}

int	p_ptr(const char *format, int len, va_list arg)
{
	unsigned long	p;
	char			*str;
	char			*key;

	key = "p";
	if (*format == key[0])
	{
		p = va_arg(arg, unsigned long);
		if (!p)
		{
			str = ERRO;
			write(1, str, ft_strlen(str));
			len = len + ft_strlen(str);
		}
		else
		{
			write(1, "0x", 2);
			ft_putnbr(p, HEXA_LOWER);
			len = len + c_digit(p, 16) + 2;
		}
	}
	return (len);
}

int	p_stdi(const char *format, int len, va_list arg)
{
	char		*str;
	long int	i;

	if (*format == 's')
	{
		str = va_arg(arg, char *);
		if (!str)
			str = ERR;
		write(1, str, ft_strlen(str));
		len = len + ft_strlen(str);
	}
	else if (*format == 'd' || *format == 'i')
	{
		i = va_arg(arg, int);
		if (i < 0)
		{
			ft_putchar('-');
			len++;
			i *= -1;
		}
		ft_putnbr(i, DECA);
		len += c_digit(i, 10);
	}
	return (len);
}

int	p_ux(const char *format, int len, va_list arg)
{
	unsigned int	nbr;
	char			*key;

	key = "uxX";
	if (*format == key[0])
	{
		nbr = va_arg(arg, unsigned int);
		ft_putnbr(nbr, DECA);
		len = len + c_digit(nbr, 10);
	}
	else if (*format == key[1])
	{
		nbr = va_arg(arg, unsigned int);
		ft_putnbr(nbr, HEXA_LOWER);
		len = len + c_digit(nbr, 16);
	}
	else if (*format == key[2])
	{
		nbr = va_arg(arg, unsigned int);
		ft_putnbr(nbr, HEXA_UPPER);
		len = len + c_digit(nbr, 16);
	}
	return (len);
}
