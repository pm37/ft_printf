/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:32:37 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/28 16:21:48 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_space_before(t_conv *conv, int max, char *output)
{
	int		tmp;

	tmp = WIDTH;
	if (FLAG.space && *output != '-' && TYPE != 'u')
	{
		RET += write(1, " ", 1);
		--tmp;
	}
	if (WIDTH > max && !FLAG.less && !(FLAG.zero && PREC == -1))
		while (--tmp >= max)
			RET += write(1, " ", 1);
}

	void	print_space_after(t_conv *conv, int max)
	{
		if (WIDTH > max && FLAG.less)
		while (--WIDTH >= max)
			RET += write(1, " ", 1);
}

void	print_zeros(t_conv *conv, int digits)
{
	int		tmp;

	tmp = PREC;
	if (tmp > digits)
		while (--tmp >= digits)
			RET += write(1, "0", 1);
}
