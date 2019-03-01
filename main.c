/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:31:05 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/03/01 14:16:51 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	float		nb;
	nb = 0.5;
//	printf("null prec : %+.0f\n", nb);
	ft_printf("null prec : %.0f\n", nb);
	printf("null prec : %.0f\n", nb);
/*	nb = -25632.2541;
	printf("null prec : %+.0f\n", nb);
	nb = -1.0123;
	printf("null prec : %+.0f\n", nb);
	nb = 12354.569874;
	printf("null prec : %+.0f\n", nb);*/

}
