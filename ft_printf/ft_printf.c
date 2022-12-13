/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:18:56 by afelipe-          #+#    #+#             */
/*   Updated: 2022/10/10 16:21:49 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	char	prefix;

	prefix = '%';
	len = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format != prefix)
		{
			write(1, format++, 1);
			len++;
		}
		else
		{
			format++;
			len = check_prefixs(format, len, arg);
			format++;
		}
	}
	va_end(arg);
	return (len);
}
