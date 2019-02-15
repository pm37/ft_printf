/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:56 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/15 19:23:09 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_sp(t_conv *conv, char *output)
{
	int		len;
	int		i;

	len = ft_strlen(output);
	if (conv->prec != -1 && conv->prec < len)
	{
		i = (int)conv->prec;
		output[i] = '\0';
	}
	len = ft_strlen(output);
	if (conv->width > len)
		if (!conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
	conv->ret += write(1, output, len);
	if (conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
}

void		print_c(t_conv *conv)
{
	if (conv->width != 0)
		if (!conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
	ft_putchar(va_arg(conv->ap, int));
	conv->ret++;
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
}

void		ft_handle_s(t_conv *conv)
{
	char	*str;

	str = ft_strdup(va_arg(conv->ap, char *));
	print_sp(conv, str);
}
