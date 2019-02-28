#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	long double ld;
	int ret, ret2;

	ld = 0.3442932409320239840982309840923804982309842903;
	ret = ft_printf("% 0+50.30Lf\n", ld);
	ret2 = printf("% 0+50.30Lf\n", ld);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	
	float	nb = 0.7637;
	char	*result;
	float positive_inf = 90000000000000000000000000000000000000000.0;
	float negative_inf = -positive_inf;
	float tricky = 999.9999;
	//ZERO PRECISION TEST
	ft_printf("{purple}{bold}0 Precision test:\n{nc}");
	ret = ft_printf("{cyan}%.0f\n{nc}", nb);
	ret2 = printf("%.0f\n", nb);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//1 PRECISION TEST
	ft_printf("{purple}{bold}1 Precision test:\n{nc}");
	ret = ft_printf("{cyan}%.1f\n{nc}", nb);
	ret2 = printf("%.1f\n", nb);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//2 PRECISION TEST
	ft_printf("{purple}{bold}2 Precision test:\n{nc}");
	ret = ft_printf("{cyan}%.2f\n{nc}", nb);
	ret2 = printf("%.2f\n", nb);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//3 PRECISION TEST
	ft_printf("{purple}{bold}3 Precision test:\n{nc}");
	ret = ft_printf("{cyan}%.3f\n{nc}", nb);
	ret2 = printf("%.3f\n", nb);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//4 PRECISION TEST
	ft_printf("{purple}{bold}4 Precision test:\n{nc}");
	ret = ft_printf("{cyan}%.4f\n{nc}", nb);
	ret2 = printf("%.4f\n", nb);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//POSITIVE ZERO TEST
	ft_printf("{purple}{bold}Positive 0 test:\n{nc}");
	ret = ft_printf("{cyan}%.0f\n{nc}", 0.0);
	ret2 = printf("%.0f\n", 0.0);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//NEGATIVE ZERO TEST
	ft_printf("{purple}{bold}Negative 0 test:\n{nc}");
	ret = ft_printf("{cyan}%.0f\n{nc}", -0.0);
	ret2 = printf("%.0f\n", -0.0);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//INFINITY TEST 1
	ft_printf("{purple}{bold}Positive Infinity test:\n{nc}");
	ret = ft_printf("{cyan}%f\n{nc}", positive_inf);
	ret2 = printf("%f\n", positive_inf);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);	
	//INFINITY TEST 2
	ft_printf("{purple}{bold}Negative Infinity test:\n{nc}");
	ret = ft_printf("{cyan}%f\n{nc}", negative_inf);
	ret2 = printf("%f\n", negative_inf);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//TRICKY TEST 1
	ft_printf("{purple}{bold}Tricky 999.9999 with %%.0 flag test 1:\n{nc}");
	ret = ft_printf("{cyan}%.0f\n{nc}", tricky);
	ret2 = printf("%.0f\n", tricky);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	//TRICKY TEST 2
	ft_printf("{purple}{bold}Tricky -959.5 with %%.0 flag test 2:\n{nc}");
	ret = ft_printf("{cyan}%.0f\n{nc}", -959.5);
	ret2 = printf("%.0f\n", -959.5);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	ft_printf("{purple}{bold}Tricky 1.1 with prec 0:\n{nc}");
	ret = ft_printf("{cyan}%.3f\n{nc}", 999.999);
	ret2 = printf("%.3f\n", 999.999);
	printf("ret = %d | ret2 = %d\n", ret, ret2);
	ft_printf("\nThe full date of today's timestamp (1550860755) is : %k\n", 1550860755);
	ft_printf("%K\n", "Feb 22 19:39:15 2019");
	long double a = 423048230423098409238049823048423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823423048230423098409238049823.0;	
	float c = 10.77777777777777777777777777777777777777777777777777777777777777777777777777777777;
	float d = -0.0;
	ft_printf("%#Lb\n", c);
	ft_printf("%b\n", 5);
	ft_printf("%hhb\n", c);
	ft_printf("Long double test\n");
	ret = ft_printf("%-15.8f\n", d);
	ret2 = printf("%-15.8f\n", d);
	printf("ret = %d | ret2 = %d\n", ret, ret2);

	ft_printf("Long double test1\n");
	ret = ft_printf("% -015.8f\n", c);
	ret2 = printf("% -015.8f\n", c);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test2\n");
	ret = ft_printf("% 015.8f\n", c);
	ret2 = printf("% 015.8f\n", c);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test3\n");
	ret = ft_printf("% -015.8f\n", c/d);
	ret2 = printf("% -015.8f\n", c/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test4\n");
	ret = ft_printf("% +15.8f\n", c/d);
	ret2 = printf("% +15.8f\n", c/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test5\n");
	ret = ft_printf("% -+015.8f\n", c);
			ft_putendl("OK");
	ret2 = printf("% -+015.8f\n", c);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test6\n");
	ret = ft_printf("% 15.8f\n", c);
	ret2 = printf("% 15.8f\n", c);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test7\n");
	ret = ft_printf("% -+015.8f\n", c/d);
	ret2 = printf("% -+015.8f\n", c/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test8\n");
	ret = ft_printf("%15.8f\n", c/d);
	ret2 = printf("%15.8f\n", c/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);


	ft_printf("Long double test9\n");
	ret = ft_printf("% -+015.8f\n", d/d);
	ret2 = printf("% -+015.8f\n", d/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test10\n");
	ret = ft_printf("%15.8f\n", d/d);
	ret2 = printf("%15.8f\n", d/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test11\n");
	ret = ft_printf("% +15.8f\n", d/d);
	ret2 = printf("% +15.8f\n", d/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);

	ft_printf("Long double test12\n");
	ret = ft_printf("%15.8f\n", d/d);
	ret2 = printf("%15.8f\n", d/d);
	printf("ret = %d | ret2 = %d\n\n", ret, ret2);
	while (1)
		;
	return (0);
}
