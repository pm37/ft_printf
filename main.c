#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

#define INIT "00000000000000000000000000000000000000000000000000.0000000000000000000000000000000000000000000000000"

int		main(int ac, char **av)
{
	unsigned long a = -429496734238888;
	int ret;
	int ret2;
	float	nb = 12341.123456789;
	char	*result;
	
	ret = ft_printf("%f\n", nb);
	ret2 = printf("%f\n", nb);
	return (0);
}
