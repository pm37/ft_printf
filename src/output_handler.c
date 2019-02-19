/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:03:46 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/19 19:07:13 by bwan-nan         ###   ########.fr       */
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
	{
		if (!conv->flag.less && !conv->flag.zero)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
		else if (conv->flag.zero && !conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, "0", 1);
	}
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
	else if (*fmt)
	{
		if (conv->width != 0)
		{
			if (!conv->flag.less && !conv->flag.zero)
				while (--conv->width)
					conv->ret += write(1, " ", 1);
			else if (conv->flag.zero && !conv->flag.less)
				while (--conv->width)
					conv->ret += write(1, "0", 1);
			conv->ret += write(1, fmt, 1);
			if (conv->flag.less)
				while (--conv->width)
					conv->ret += write(1, " ", 1);
		}
	}
	return (conv->length + 1);
}
