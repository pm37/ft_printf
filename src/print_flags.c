/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:32:37 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/20 16:24:50 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_before(t_conv *conv, int max, char *output)
{
	int		tmp;

	tmp = conv->width;
	if (conv->width > max && !conv->flag.less && !conv->flag.zero)
		while (--tmp >= max)
			conv->ret += write(1, " ", 1);
	if (conv->flag.space && *output != '-' && conv->conv_type != 'u')
	{
		conv->ret += write(1, " ", 1);
		--conv->width;
	}
}

void	print_space_after(t_conv *conv, int max)
{
	if (conv->width > max && conv->flag.less)
		while (--conv->width >= max) 
			conv->ret += write(1, " ", 1);
}

void	print_zeros(t_conv *conv, int digits)
{
	int		tmp;

	tmp = conv->prec;
	if (tmp > digits)
		while (--tmp >= digits)
			conv->ret += write(1, "0", 1);
}
