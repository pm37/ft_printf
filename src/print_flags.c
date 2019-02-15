/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:32:37 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/15 14:39:27 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_before(t_conv *conv, int prec, int len)
{
	if (conv->width > prec && conv->width > len)
		if (!conv->flag.less)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
}

void	print_space_after(t_conv *conv, int prec, int len)
{
	if (conv->width > prec + conv->flag.plus && conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
}
