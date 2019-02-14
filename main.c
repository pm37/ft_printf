#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	char	c;
	int		ret;
	char	str[]="hello";

	c = 'd';
	ret = ft_printf("%s", str);
	//ret = ft_printf("%c\n", c);
	if (ac == 2)
		ret = ft_printf("%d", ft_atoi(av[1])); 
	//printf("\nle vrai:\n%020.10f", nbr);
	//floats:
	//printf renvoie le long max suivi de 0 des qu'on demande trop haut...
	//
	printf("\nret de ft_printf : %d\n", ret);
	return (0);
}
