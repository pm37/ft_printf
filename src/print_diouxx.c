/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:44:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/15 14:20:58 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_di(t_conv *conv, char *output)
{
	int		len;
	int		prec;

	prec = conv->prec + conv->flag.plus;
	len = ft_strlen(output) + conv->flag.plus;
	if (conv->width > prec && conv->width > len)
		if (!conv->flag.less)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
	if (conv->flag.plus && *output != '-')
		conv->ret += write(1, "+", 1);
	if (conv->width > conv->prec + conv->flag.plus && conv->width > len)
		if (!conv->flag.less && conv->flag.zero && conv->prec == -1)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, "0", 1);
	if (conv->prec != -1)
		if (len < conv->prec)
			while (--conv->prec >= len)
				conv->ret += write(1, "0", 1);
	conv->ret += write(1, output, ft_strlen(output));
	if (conv->width > prec + conv->flag.plus && conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
}

void	print_x(t_conv *conv, char *output)
{
	int		len;
	int		prec;

	prec = conv->prec + conv->flag.sharp * 2;
	len = ft_strlen(output) + conv->flag.sharp * 2;
	if (!conv->flag.zero && conv->width > prec
		&& conv->width > len && !conv->flag.less)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
	if (conv->flag.sharp && conv->conv_type == 'x')
		conv->ret += write(1, "0x", 2);
	else if (conv->flag.sharp)
		conv->ret += write(1, "0X", 2);
	if (conv->width > prec && conv->width > len && 
	!conv->flag.less && conv->flag.zero && conv->prec == -1)
		while (--conv->width >= prec && conv->width >= len)
			conv->ret += write(1, "0", 1);
	if (conv->prec != -1 && len < conv->prec)
			while (--conv->prec >= len)
				conv->ret += write(1, "0", 1);
	conv->ret += write(1, output, ft_strlen(output));
	if (conv->width > prec + conv->flag.sharp * 2 && conv->width > len && conv->flag.less)
			while (--conv->width >= prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
}

void	print_o(t_conv *conv, char *output)
{
	int		len;
	int		prec;

	prec = conv->prec + conv->flag.sharp;
	len = ft_strlen(output) + conv->flag.sharp;
	if (!conv->flag.zero && conv->width > prec
		&& conv->width > len && !conv->flag.less)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
	if (conv->flag.sharp)
		conv->ret += write(1, "0", 1);
	if (conv->width > prec && conv->width > len && 
	!conv->flag.less && conv->flag.zero && conv->prec == -1)
		while (--conv->width >= prec && conv->width >= len)
			conv->ret += write(1, "0", 1);
	if (conv->prec != -1 && len < conv->prec)
			while (--conv->prec >= len)
				conv->ret += write(1, "0", 1);
	conv->ret += write(1, output, ft_strlen(output));
	if (conv->width > prec + conv->flag.sharp && conv->width > len && conv->flag.less)
			while (--conv->width >= prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
}
