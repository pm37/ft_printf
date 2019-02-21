/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:07:19 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/21 14:23:35 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_handle_f(t_conv *conv)
{
	char		*output;

	if (conv->prec == -1)
		conv->prec = 6;
	output = ft_lftoa(va_arg(conv->ap, double), conv->prec);
	conv->ret += write(1, output, ft_strlen(output));
	ft_strdel(&output);
}
