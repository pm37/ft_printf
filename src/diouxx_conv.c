/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:51:24 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/21 17:35:00 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	ft_handle_di(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_llitoa((char)va_arg(conv->ap, long long));
	else if (conv->size.h)
		str = ft_llitoa((short)va_arg(conv->ap, long long));
	else if (conv->size.ll || conv->size.j)
		str = ft_llitoa(va_arg(conv->ap, long long));
	else if (conv->size.l)
		str = ft_llitoa(va_arg(conv->ap, long long));
	else
		str = ft_llitoa(va_arg(conv->ap, int));
	print_di(conv, str);
	ft_strdel(&str);
}

void	ft_handle_o(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_ullitoa_base((unsigned char)va_arg(conv->ap, int), 8);
	else if (conv->size.h)
		str = ft_ullitoa_base((unsigned short)va_arg(conv->ap, long long), 8);
	else if (conv->size.l || conv->size.ll || conv->size.j)
		str = ft_ullitoa_base(va_arg(conv->ap, long long), 8);
	else
		str = ft_ullitoa_base((unsigned int)va_arg(conv->ap, int), 8);
	print_o(conv, str);
	ft_strdel(&str);
}

void	ft_handle_u(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_ullitoa((unsigned char)va_arg(conv->ap, ULL));
	else if (conv->size.h)
		str = ft_ullitoa(va_arg(conv->ap, ULL));
	else if (conv->size.ll || conv->size.j)
		str = ft_ullitoa(va_arg(conv->ap, ULL));
	else if (conv->size.l)
		str = ft_ullitoa((ULL)va_arg(conv->ap, ULL));
	else
		str = ft_ullitoa(va_arg(conv->ap, unsigned int));
	print_u(conv, str);
	ft_strdel(&str);
}

void	ft_handle_xx(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_ullitoa_base((unsigned char)va_arg(conv->ap, int), 16);
	else if (conv->size.h)
		str = ft_ullitoa_base((unsigned short)va_arg(conv->ap, long long), 16);
	else if (conv->size.l || conv->size.ll || conv->size.j)
		str = ft_ullitoa_base(va_arg(conv->ap, long long), 16);
	else
		str = ft_ullitoa_base((unsigned int)va_arg(conv->ap, int), 16);
	if (conv->conv_type == 'X')
		ft_strtoupper(str);
	print_x(conv, str);
	ft_strdel(&str);
}
