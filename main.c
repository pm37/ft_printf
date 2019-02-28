/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:31:05 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/28 15:59:22 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
int	ret;
int	ret2;
int	nb = 42;
	if (ac == 2)
		ft_printf("%K\n", av[1]);
	else
	{
	
	ft_putendl("OURS");
	ret = ft_printf("{% 03d}", 0); 
	ft_putendl("\n\n\n");
	ft_putendl("REAL");
	ret2 = printf("{% 03d}", 0); 
	printf("\n\nret = %d | ret2 = %d", ret, ret2);
	}
}
