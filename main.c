#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

int		main(int ac, char **av)
{
	unsigned long a = -429496734238888;
	int ret;
	int ret2;

	ret =  printf("{%f}", 10.0);
	printf("\n\n");
	ret2 =   ft_printf("{%f}", 10.0);
	printf("\nret = %d | ret2 = %d\n",ret, ret2);
	return (0);
}
