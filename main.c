#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		main(int ac, char **av)
{
	char	str[]="hello";
	double  nbr = 55455454354343543543543543549.12345678909876543210555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555;
	//void *ptr;`
	//nbr /= 1.23;
	//ptr = &str[0];

	ft_printf("%.80f", nbr);
	printf("\n\n\n%.80f\n", nbr);
	//printf("\nle vrai:\n%020.10f", nbr);
	//floats:
	//printf renvoie le long max des suivi de 0 des qu'on demande trop haut...
	//
}
