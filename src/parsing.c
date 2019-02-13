/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:37:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/13 12:09:50 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_size(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
//			ft_putendl("size");
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
//			ft_putendl("precision");
	if (fmt[i] == '.')
	{	
		i++;
		conv->prec = ft_atoi(&fmt[i]);
		while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
			i++;
	}
	conv->length += i;
	return (ft_check_size(&fmt[i], conv));
}

static int		ft_check_width(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
//			ft_putendl("width");
	conv->width = ft_atoi(fmt);
	while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
		i++;
	conv->length += i;
	return (ft_check_prec(&fmt[i], conv));
}

int				ft_check_flags(char *fmt, t_conv *conv)
{
	int i;

//			ft_putendl("flags");
	i = -1;
	while (fmt[++i] && (fmt[i] == ' ' || fmt[i] == '#' || fmt[i] == '+' ||  fmt[i] == '-' || fmt[i] == '0'))
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

