#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	int ret;
	int	ret2;
	int ret3;

	ret = 0;
	
	ret =   ft_printf("%k %s %d\n", 324324234, "bonjour", 15);
	ret2 = ft_printf("%K\n", "Apr 11 20:03:54 1980");
	ret3 =   ft_printf("%d\n", 324324234);
	printf("\nret = %d | ret2 = %d | ret3 = %d\n",ret, ret2, ret3);
	return (0);

}
