#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	char	str[]="hello";


	ft_printf("%.2s\n", str);
	//printf("\nle vrai:\n%020.10f", nbr);
	//floats:
	//printf renvoie le long max suivi de 0 des qu'on demande trop haut...
	//
	return (0);
}
