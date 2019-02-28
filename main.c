#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int		main(void)
{
	long double ld;

	ld = 0.3442932409320239840982309840923804982309842903;
	ft_printf("%.30Lf\n", ld);
	printf("%.30Lf\n", ld);
}
