#include <stdio.h>
#include <stdarg.h>
#include "inc/ft_printf.h"

int		main(int ac, char **av)
{
	char	str[]="hello";
	double  nbr = 1.123456789123456789123456789123456789123456789000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000022222222222222222222222222222222222222222;
	//void *ptr;
	//nbr /= 1.23;
	//ptr = &str[0];

	ft_printf("%.1050f", nbr);
	printf("\n\n\n%.1050f\n", nbr);
	//printf("\nle vrai:\n%020.10f", nbr);
	//floats:
	//printf renvoie le long max suivi de 0 des qu'on demande trop haut...
	//
}
