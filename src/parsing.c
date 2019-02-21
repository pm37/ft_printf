/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:37:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/20 19:32:00 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_size(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
	conv->size.hh = *fmt == 'h' && fmt[1] == 'h' ? 1 : 0;
	conv->size.h = *fmt == 'h' && fmt[1] != 'h' ? 1 : 0;
	conv->size.ll = *fmt == 'l' && fmt[1] == 'l' ? 1 : 0;
	conv->size.l = *fmt == 'l' && fmt[1] != 'l' ? 1 : 0;
	conv->size.j = *fmt == 'j' ? 1 : 0;
	if (conv->size.h || conv->size.hh || conv->size.l
	|| conv->size.ll || conv->size.j)
		i += conv->size.hh == 1 || conv->size.ll == 1 ? 2 : 1;
	if (fmt[i] == 'o' && conv->flag.sharp && conv->prec == -1)
		conv->prec = 0;
	conv->length += i;
	return (output_handler(&fmt[i], conv));
}

static int		ft_check_prec(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
	if (fmt[i] == '.')
	{
		i++;
		conv->prec = ft_atoi(&fmt[i]);
		while (fmt[i] && ft_isdigit(fmt[i]))
			i++;
	}
	if (conv->prec > 0)
		conv->flag.zero = 0;
	conv->length += i;
	return (ft_check_size(&fmt[i], conv));
}

static int		ft_check_width(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
	conv->width = ft_atoi(fmt);
	while (fmt[i] && ft_isdigit(fmt[i]))
		i++;
	conv->length += i;
	return (ft_check_prec(&fmt[i], conv));
}

static int		ft_is_flag(char c)
{
	return (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0');
}

int				ft_check_flags(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
	while (fmt[i] && ft_is_flag(fmt[i]))
	{
		if (fmt[i] == ' ')
			conv->flag.space = 1;
		else if (fmt[i] == '#')
			conv->flag.sharp = 1;
		else if (fmt[i] == '+')
			conv->flag.plus = 1;
		else if (fmt[i] == '-')
			conv->flag.less = 1;
		else if (fmt[i] == '0')
			conv->flag.zero = 1;
		i++;
	}
	if (conv->flag.plus && conv->flag.space)
		conv->flag.space = 0;
	conv->length += i;
	return (ft_check_width(&fmt[i], conv));
}
