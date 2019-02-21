#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

int		main(int ac, char **av)
{
	unsigned long a = -429496734238888;
	int ret;
	int ret2;
	double	nb = 123456789012345678901.123456789;
	
	ret =  printf("le vrai:\n%.011lf", nb);
	printf("\n\n");
	ret2 =   ft_printf("le mien:\n%.011lf", nb);
	printf("\n\nret = %d | ret2 = %d\n",ret, ret2);
	return (0);
}
