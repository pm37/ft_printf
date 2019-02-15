#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	int a = 125;
	int ret;
	
	ret =      ft_printf("%03.2d", 0);
	printf("\nret = %d\n", ret);
	return (0);
}
