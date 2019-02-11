/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:52:36 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/11 20:47:57 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_sp_p(t_conv *conv)
{
	size_t	len;
	int		i;

	len = ft_strlen(conv->str_val);
	if (conv->prec != -1 && conv->prec < len)
	{
		i = (int)conv->prec;
		conv->str_val[i] = '\0';
	}
	len = ft_strlen(conv->str_val);
	if (conv->width > len)
		if (!conv->flag.less)
			while (--conv->width >= len)
				ft_putchar(' ');
	ft_putstr(conv->str_val);
	if (conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= len)
				ft_putchar(' ');
}

void	ft_handle_di_p(t_conv *conv)
{
	size_t	len;
	int		prec;

	prec = conv->prec;
	len = ft_strlen(conv->str_val);
	if (conv->width > conv->prec + conv->flag.plus && conv->width > len + conv->flag.plus)
		if (!conv->flag.less && conv->prec != -1) 
			while (--conv->width >= conv->prec + conv->flag.plus && conv->width >= len + conv->flag.plus)
				ft_putchar(' ');
	if (conv->flag.plus)
		ft_putchar('+');
	if (conv->width > conv->prec + conv->flag.plus && conv->width > len + conv->flag.plus)
		if (!conv->flag.less && conv->flag.zero && conv->prec == -1)
			while (--conv->width >= conv->prec + conv->flag.plus && conv->width >= len + conv->flag.plus)
				ft_putchar('0');
	if (conv->prec != -1)
		if (len < conv->prec)
			while (--conv->prec >= len)
				ft_putchar('0');
	ft_putstr(conv->str_val);
	if (conv->width > prec + conv->flag.plus && conv->width > len + conv->flag.plus)
		if (conv->flag.less)
			while (--conv->width >= prec + conv->flag.plus && conv->width >= len + conv->flag.plus)
				ft_putchar(' ');
}
