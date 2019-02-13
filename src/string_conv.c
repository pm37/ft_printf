/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:56 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/13 14:26:35 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_sp_p(t_conv *conv, char *output)
{
	size_t	len;
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
				ft_putchar(' ');
	ft_putstr(output);
	if (conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= len)
				ft_putchar(' ');
}

void		ft_handle_di_p(t_conv *conv, char *output)
{
	int		len;
	int		prec;

	prec = conv->prec + conv->flag.plus;
	len = ft_strlen(output) + conv->flag.plus;
	if (conv->width > conv->prec && conv->width > len)
		if (!conv->flag.less && conv->prec != -1)
			while (--conv->width >= conv->prec && conv->width >= len)
				ft_putchar(' ');
	if (conv->flag.plus)
		ft_putchar('+');
	if (conv->width > conv->prec + conv->flag.plus && conv->width > len)
		if (!conv->flag.less && conv->flag.zero && conv->prec == -1)
			while (--conv->width >= conv->prec && conv->width >= len)
				ft_putchar('0');
	if (conv->prec != -1)
		if (len < conv->prec)
			while (--conv->prec >= len)
				ft_putchar('0');
	ft_putstr(output);
	if (conv->width > prec + conv->flag.plus && conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= prec && conv->width >= len)
				ft_putchar(' ');
	ft_strdel(&output);
}

void		ft_handle_c(t_conv *conv)
{
	if (conv->width != 0)
		if (!conv->flag.less)
			while (--conv->width)
				ft_putchar(' ');
	ft_putchar(va_arg(conv->ap, int));
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width)
				ft_putchar(' ');
}

void		ft_handle_s(t_conv *conv)
{
	char	*str;

	str = ft_strdup(va_arg(conv->ap, char *));
	ft_handle_sp_p(conv, str);
}
