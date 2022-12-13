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
