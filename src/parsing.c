/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:37:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/14 12:57:07 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_size(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
	if (fmt[0] == 'h')
	{
		if (fmt[1] == 'h')
			conv->size.hh = 1;
		else
			conv->size.h = 1;
		i = (conv->size.h == 1) ? i + 1 : i + 2;
	}
	else if (fmt[0] == 'l')
	{
		if (fmt[1] == 'l')
			conv->size.ll = 1;
		else
			conv->size.l = 1;
		i = (conv->size.l == 1) ? i + 1 : i + 2;
	}
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

	i = -1;
	while (fmt[++i] && ft_is_flag(fmt[i]))
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
	}
	conv->length += i;
	return (ft_check_width(&fmt[i], conv));
}
