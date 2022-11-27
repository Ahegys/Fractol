#include "../includes/fractal.h"

int		potency(int number, int power)
{
	int	i;
	int	n;
	
	i = 0;
	n = 1;
	while (i < power)
	{
		n *= number;
		i++;
	}
	return (n);
}
