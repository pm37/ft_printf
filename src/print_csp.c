/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:56 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/25 17:45:43 by pimichau         ###   ########.fr       */
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
		i = conv->conv_type == 'p' ? (int)conv->prec + 2 : (int)conv->prec;
		output[i] = '\0';
	}
	len = ft_strlen(output);
	if (conv->width > len)
	{
		if (!conv->flag.less && !conv->flag.zero)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
		else if (conv->flag.zero && !conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, "0", 1);
	}
	conv->ret += write(1, output, len);
	if (conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
}

int			print_c(t_conv *conv)
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
	ft_putchar(va_arg(conv->ap, int));
	conv->ret++;
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
	return (0);
}

int		handle_p(t_conv *conv)
{
	char	*str;
	char	*tmp;

	if (!(str = ft_ullitoa_base((uintptr_t)va_arg(conv->ap, void *), 16)))
		return (-1);
	tmp = str;
	if (!(str = ft_strjoin("0x", str)))
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	print_sp(conv, str);
	ft_strdel(&str);
	return (0);
}

int			handle_s(t_conv *conv)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(conv->ap, char *);
	if (tmp)
	{
		if (!(str = ft_strdup(tmp)))
			return (-1);
		print_sp(conv, str);
		ft_strdel(&str);
	}
	else
		conv->ret += write(1, "(null)", 6);
	return (0);
}
