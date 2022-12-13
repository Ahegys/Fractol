/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:17:34 by afelipe-          #+#    #+#             */
/*   Updated: 2022/10/10 19:28:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECA "0123456789"
# define ERR "(null)"
# define ERRO "(nil)"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		check_prefixs(const char *format, int len, va_list arg);
int		p_char(const char *format, int len, va_list arg);
int		p_stdi(const char *format, int len, va_list arg);
int		p_ptr(const char *format, int len, va_list arg);
int		p_ux(const char *format, int len, va_list arg);
void	ft_putnbr(unsigned long num, char *n);
int		c_digit(unsigned long num, int base);
int		ft_printf(const char *format, ...);
int		ft_strlen(const char *s);
void	ft_putchar(char c);

#endif
