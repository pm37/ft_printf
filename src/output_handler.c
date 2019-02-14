/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:03:46 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/14 15:39:25 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_handle_conv(t_conv *conv)
{
	int i;

	i = 0;
	while (conv->conv_type != conv->type[i])
		i++;
	conv->f[i](conv);
}

static void		ft_handle_percent(t_conv *conv)
{	

	if (conv->width != 0)
		if (!conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
	conv->ret += write(1, "%", 1);
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
}

int				output_handler(char *fmt, t_conv *conv)
{
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd'
			|| *fmt == 'i' || *fmt == 'o' || *fmt == 'u' || *fmt == 'x'
			|| *fmt == 'X' || *fmt == 'f')
	{
		conv->conv_type = *fmt;
		ft_handle_conv(conv);
	}
	else if (*fmt == '%')
		ft_handle_percent(conv);
	else
		ft_init_conv(conv);
	return (conv->length + 1);
}
