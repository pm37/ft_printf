/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:31:05 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/28 17:46:08 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
int	ret;
int	ret2;
float	nb = 42.0;
	if (ac == 2)
		ft_printf("%K\n", av[1]);
	else
	{
   /* ft_printf("space:% f\n", nb);
    printf("space:% f\n", nb);

    ft_printf("plus:%+f\n", nb);
    printf("plus:%+f\n", nb);
    
    ft_printf("hash:%#f\n", nb);
    printf("hash:%#f\n", nb);

    ft_printf("precision:%.2f\n", nb);
    printf("precision:%.2f\n", nb);

    ft_printf("big prec:%.14f\n", nb);
    printf("big prec:%.14f\n", nb);

    ft_printf("precision + hash:%#.0f\n", nb);
    printf("precision + hash:%#.0f\n", nb);

    ft_printf("space + prec:% .5f\n", nb);
    printf("space + prec:% .5f\n", nb);*/

    ft_printf("space + prec + hash:%# .0f\n", nb);
    printf("space + prec + hash:%# .0f\n", nb);

 /*   ft_printf("space + prec + hash:% #.0f\n", nb);
    printf("space + prec + hash:% #.0f\n", nb);

    ft_printf("Plus + prec / grande:%+.5f\n", nb);
    printf("Plus + prec / grande:%+.5f\n", nb);

    ft_printf("Plus + prec / petite:%+.0f\n", nb);
    printf("Plus + prec / petite:%+.0f\n", nb);

    ft_printf("Plus + prec + hash:%#+.0f\n", nb);
    printf("Plus + prec + hash:%#+.0f\n", nb);

    ft_printf("Prec + 0:%0.5f\n", nb);
    printf("Prec + 0:%0.5f\n", nb);

    ft_printf("Prec + minus:%-.5f\n", nb);
    printf("Prec + minus:%-.5f\n", nb);

    ft_printf("size:%5f\n", nb);
    printf("size:%5f\n", nb);

    ft_printf("size + space:% 5f\n", nb);
    printf("size + space:% 5f\n", nb);

    ft_printf("size + plus:%+5f\n", nb);
    printf("size + plus:%+5f\n", nb);

    ft_printf("size + space:%# 5f\n", nb);
    printf("size + space:%# 5f\n", nb);

    ft_printf("size + plus:%#+5f\n", nb);
    printf("size + plus:%#+5f\n", nb);

    ft_printf("size + minus:%-5f\n", nb);
    printf("size + minus:%-5f\n", nb);*/

   /* ft_printf("size + 0:%05f\n", nb);
    ft_printf("size + 0 + plus:%+05f\n", nb);
    ft_printf("size + 0 + plus:%0+5f\n", nb);
    ft_printf("size + 0 + prec:%05.3f\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
    ft_printf("size + minus + prec:%-5.3f\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);*/
    
 	}
}
