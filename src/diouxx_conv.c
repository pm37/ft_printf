/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:51:24 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/15 14:13:24 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_di(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_strdup(ft_llitoa((char)va_arg(conv->ap, long long)));
	else if (conv->size.h)
		str = ft_strdup(ft_llitoa((short)va_arg(conv->ap, long long)));
	else if (conv->size.ll)
		str = ft_strdup(ft_llitoa(va_arg(conv->ap, long long)));
	else if (conv->size.l)
		str = ft_strdup(ft_llitoa((long)va_arg(conv->ap, long long)));
	else
		str = ft_strdup(ft_llitoa(va_arg(conv->ap, int)));
	print_di(conv, str);
	ft_strdel(&str);
}

void	ft_handle_u(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_strdup(ft_llitoa((unsigned char)va_arg(conv->ap, unsigned long long)));
	else if (conv->size.h)
		str = ft_strdup(ft_llitoa((unsigned short)va_arg(conv->ap, unsigned long long)));
	else if (conv->size.ll)
		str = ft_strdup(ft_ullitoa(va_arg(conv->ap, unsigned long long)));
	else if (conv->size.l)
		str = ft_strdup(ft_llitoa((unsigned long)va_arg(conv->ap, unsigned long long)));
	else
		str = ft_strdup(ft_llitoa(va_arg(conv->ap, unsigned int)));
	print_di(conv, str);
	ft_strdel(&str);
}

void	ft_handle_o(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_strdup(ft_llitoa_base((char)va_arg(conv->ap, long long), 8, 0));
	else if (conv->size.h)
		str = ft_strdup(ft_llitoa_base((short)va_arg(conv->ap, long long), 8, 0));
	else if (conv->size.ll)
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, long long), 8, 0));
	else if (conv->size.l)
		str = ft_strdup(ft_llitoa_base((long)va_arg(conv->ap, long long), 8, 0));
	else
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, int), 8, 0));
	print_o(conv, str);
	ft_strdel(&str);
}

void	ft_handle_x(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_strdup(ft_llitoa_base((char)va_arg(conv->ap, int), 16, 1));
	else if (conv->size.h)
		str = ft_strdup(ft_llitoa_base((short)va_arg(conv->ap, int), 16, 1));
	else if (conv->size.ll)
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, unsigned long long), 16, 1));
	else if (conv->size.l)
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, unsigned long), 16, 1));
	else
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, unsigned int), 16, 1));
	print_x(conv, str);
	ft_strdel(&str);
}

void	ft_handle_X(t_conv *conv)
{
	char	*str;

	if (conv->size.hh)
		str = ft_strdup(ft_llitoa_base((char)va_arg(conv->ap, long long), 16, 0));
	else if (conv->size.h)
		str = ft_strdup(ft_llitoa_base((short)va_arg(conv->ap, long long), 16, 0));
	else if (conv->size.ll)
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, long long), 16, 0));
	else if (conv->size.l)
		str = ft_strdup(ft_llitoa_base((long)va_arg(conv->ap, long long), 16, 0));
	else
		str = ft_strdup(ft_llitoa_base(va_arg(conv->ap, unsigned int), 16, 0));
	print_x(conv, str);
	ft_strdel(&str);
}

