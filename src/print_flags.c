/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:32:37 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/27 12:50:33 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_before(t_conv *conv, int max, char *output)
{
	int		tmp;

	tmp = WIDTH;
	if (WIDTH > max && !FLAG.less && !FLAG.zero)
		while (--tmp >= max)
			RET += write(1, " ", 1);
		if (FLAG.space && *output != '-' && TYPE != 'u')
		{
			RET += write(1, " ", 1);
			--WIDTH;
		}
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
