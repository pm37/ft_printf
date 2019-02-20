/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:10:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/20 19:10:57 by bwan-nan         ###   ########.fr       */
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
		else
			conv.ret += write(1, &format[i], 1);
		if (format[i] == '\0')
			break ;
	}
	va_end(conv.ap);
	return (conv.ret);
}
