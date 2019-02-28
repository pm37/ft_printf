#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	int	ret;
	int	ret2;



//	ft_printf("{cyan} float min test {nc}\n");
//	ft_printf("{red}%.128f{nc}\n", FLT_MIN);
//	ft_printf("%f\n", FLT_MAX);

//	ft_putendl("\n\n\n");
//	ft_printf("{cyan} double min test {nc}\n");
//	ft_printf("%lf\n", DBL_MAX);
//	ft_printf("{red}%.1022lf{nc}\n", DBL_MIN);

//	ft_putendl("\n\n\n");
//	ft_printf("{cyan} double min test {nc}\n");
	ft_printf("%.16382Lf\n", LDBL_MIN);
//	printf("%Lf\n", LDBL_MAX);
	//ft_printf("{red}%.16382Lf{nc}\n", LDBL_MIN);
	return (0);
}
