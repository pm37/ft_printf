#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		main(int ac, char **av)
{
	char	str[]="hello";
	double  nbr = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999912345678901234567.0;
	//void *ptr;
	//nbr /= 1.23;
	//ptr = &str[0];

	ft_printf("%f", nbr);
	printf("\n\n\n%f\n", nbr);
	//printf("\nle vrai:\n%020.10f", nbr);
	//floats:
	//printf renvoie le long max suivi de 0 des qu'on demande trop haut...
	//
}
