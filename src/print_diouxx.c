/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:44:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/18 15:11:17 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void		print_di(t_conv *conv, char *output)
{
	int		len;
	int		prec;
	int		max;
	int		digits;

	prec = *output != '-' ? conv->prec + conv->flag.plus : conv->prec + 1;
	len = *output != '-' ? ft_strlen(output) + conv->flag.plus : ft_strlen(output);
	max = ft_max(prec, len);
	print_space_before(conv, max, output);
	if (conv->flag.plus && *output != '-')
		conv->ret += write(1, "+", 1);	
	digits = *output == '-' ? ft_strlen(output) - 1 : ft_strlen(output);
	conv->ret += *output == '-' ? write(1, "-", 1) : 0;
	if (conv->width > max)
		if (!conv->flag.less && conv->flag.zero && conv->prec == -1)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, "0", 1);
	print_zeros(conv, digits);
	if (!(ft_strequ(output, "0") && conv->prec == 0))
	{
		if (*output != '-')
			conv->ret += write(1, output, digits);
		else
			conv->ret += write(1, output + 1, digits);
	}
	print_space_after(conv, max);
}

void		print_u(t_conv *conv, char *output)
{
	int		len;
	int		prec;
	int		max;
	int		digits;

	prec = *output != '-' ? conv->prec + conv->flag.plus : conv->prec + 1;
	len = *output != '-' ? ft_strlen(output) + conv->flag.plus : ft_strlen(output);
	max = ft_max(prec, len);
	print_space_before(conv, max, output);
	//if (conv->flag.plus && *output != '-')
	//	conv->ret += write(1, "+", 1);	
	digits = *output == '-' ? ft_strlen(output) - 1 : ft_strlen(output);
	conv->ret += *output == '-' ? write(1, "-", 1) : 0;
	if (conv->width > max)
		if (!conv->flag.less && conv->flag.zero && conv->prec == -1)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, "0", 1);
	print_zeros(conv, digits);
	if (!(ft_strequ(output, "0") && conv->prec == 0))
	{
		if (*output != '-')
			conv->ret += write(1, output, digits);
		else
			conv->ret += write(1, output + 1, digits);
	}
	print_space_after(conv, max);
}
void	print_x(t_conv *conv, char *output)
{
	int		len;
	int		prec;
	int		is_width;

//	ft_putstr("conv->width: ");
//	ft_putnbr(conv->width);
//	ft_putendl("");

	is_width = conv->width > 0 ? 1 : 0;
	prec = conv->prec + conv->flag.sharp * 2;
	len = ft_strlen(output) + conv->flag.sharp * 2;
	if (!conv->flag.zero && conv->width > prec
			&& conv->width > len && !conv->flag.less)
		while (--conv->width >= conv->prec && conv->width >= len)
			conv->ret += write(1, " ", 1);
	if (conv->flag.sharp && conv->conv_type == 'x' && !ft_strequ("0", output))
		conv->ret += write(1, "0x", 2);
	else if (conv->flag.sharp && !ft_strequ("0", output))
		conv->ret += write(1, "0X", 2);
	if (conv->width > prec && conv->width > len && 
			!conv->flag.less && conv->flag.zero && conv->prec == -1)
		while (--conv->width >= prec && conv->width >= len)
			conv->ret += write(1, "0", 1);
	if (conv->prec != -1 && len < conv->prec)
		while (--conv->prec >= len)
			conv->ret += write(1, "0", 1);
	if (!(ft_strequ("0", output) && conv->prec == 0))
		conv->ret += write(1, output, ft_strlen(output));
	else if (ft_strequ("0", output) && is_width && conv->prec == 0)
		conv->ret += write(1, " ", 1);
	if (conv->width > prec + conv->flag.sharp * 2 && conv->width > len && conv->flag.less)
		while (--conv->width >= prec && conv->width >= len)
			conv->ret += write(1, " ", 1);
}

void	print_o(t_conv *conv, char *output)
{
	int		len;
	int		prec;
	int		is_width;

	is_width = conv->width > 0 ? 1 : 0;
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
	if (!(ft_strequ("0", output) && conv->prec == 0))
		conv->ret += write(1, output, ft_strlen(output));
	else if (ft_strequ("0", output) && is_width && conv->prec == 0)
		conv->ret += write(1, " ", 1);
	if (conv->width > prec + conv->flag.sharp && conv->width > len && conv->flag.less)
		while (--conv->width >= prec && conv->width >= len)
			conv->ret += write(1, " ", 1);
}
