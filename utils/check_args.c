#include "../includes/fractal.h"

int cmp(const char *s1, const char *s2)
{

	const unsigned char *us1;
	const unsigned char *us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 == *us2 && *us1 != '\0')
	{
    	us1++;
    	us2++;
	}
	return (*us1 > *us2) - (*us1 < *us2);
}

double	float_conv(const char *str)
{
	int		sign;
	double	result;
	double	power;
	int		i;

	sign = 1;
	result = 0;
	power = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (digits(str[i]))
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (digits(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		power *= 10;
	}
	return (sign * result / power);
}

int	digits(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (arg);
	return (0);
}

int	doubles(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != '.')
	{
		if (digits(*str))
			return (0);
		str++;
	}
	if (*str == '.')
	{
		if (!digits(*(str + 1)))
			return (0);
		str++;
		while (*str)
		{
			if (!digits(*str))
				return (0);
			str++;
		}
	}
	return (1);
}
