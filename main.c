#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	int ret;
	int ret2;
	float	nb = 150555555555555555555555555555.123456789;
	char	*result;
	
	ret = ft_printf("{cyan}%f\n{nc}", nb);
	ret2 = printf("%f\n", nb);
	printf("ret = %d | ret2 = %d\n", ret, ret2);
	ft_printf("The full date of today's timestamp (1550860755) is : %k\n", 1550860755);
	ft_printf("%K\n", "Feb 22 19:39:15 2019");
	return (0);

}
