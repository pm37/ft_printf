#include <stdio.h>
#include <stdarg.h>
#include "inc/ft_printf.h"

int		main(int ac, char **av)
{
	int r;
	int ft_r;
	
	ft_r = ft_printf("%8c", 'a');
	ft_putendl("");
	ft_putnbr(ft_r);
	ft_putendl("");
	r = printf("%8c", 'a');
	ft_putendl("");
	ft_putnbr(r);
	ft_putendl("");
}
