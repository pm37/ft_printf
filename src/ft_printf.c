/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:10:38 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/21 16:47:16 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	t_conv		conv;

	i = -1;
	va_start(conv.ap, format);
	ft_init_conv(&conv);
	ft_init_fp(&conv);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i += ft_check_flags((char *)&format[i + 1], &conv);
			ft_init_conv(&conv);
		}
		else if (format[i] == '{')
			color_check(&conv, &format[i], &i);
		else
			conv.ret += write(1, &format[i], 1);
		if (format[i] == '\0')
			break ;
	}
	va_end(conv.ap);
	return (conv.ret);
}
