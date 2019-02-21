#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	int ret;

	ret = 0;
	
	ret =   ft_printf("%k", 324324234);
	printf("\nret = %d\n",ret);
	return (0);
}
