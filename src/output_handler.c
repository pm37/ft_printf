/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:03:46 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/26 18:11:00 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_undef_char(t_conv *conv, char *fmt)
{
	if (!conv->flag.less && !conv->flag.zero)
		while (--conv->width > 0)
			conv->ret += write(1, " ", 1);
	else if (conv->flag.zero && !conv->flag.less)
		while (--conv->width > 0)
			conv->ret += write(1, "0", 1);
	conv->ret += write(1, fmt, 1);
	if (conv->flag.less)
		while (--conv->width > 0)
			conv->ret += write(1, " ", 1);
}

static int		handle_conv(t_conv *conv)
{
	int i;

	i = 0;
	while (conv->conv_type != conv->type[i])
		i++;
	if (conv->f[i](conv) == -1)
		return (-1);
	return (0);
}

static void		handle_percent(t_conv *conv)
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
	if (ft_strchr(OPTIONS, *fmt))
	{
		conv->conv_type = *fmt;
		if (handle_conv(conv) == -1)
			return (-1);
		if (conv->prec > 0 && TYPE != 'f')
			FLAG.zero = 0;
		else if (conv->prec < -1)
			conv->prec = 0;
	}
	else if (*fmt == '%')
		handle_percent(conv);
	else if (*fmt)
		print_undef_char(conv, fmt);
	return (conv->length + 1);
}
