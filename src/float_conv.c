/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:18:08 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/22 18:20:07 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*set_min(int exp)
{
	char	*min;
	int		i = 0;

	min = ft_strdup(INIT1);
	i = 0;
	if (exp >= 23)
	{
		while (i < exp - 23 - 1)
		{
			str_mult_by_two(&min);
			i++;
		}
	}
	else
	{
		while (i < 23 - exp + 1)
		{
			str_div_by_two(&min);
			i++;
		}
	}
	return (min);
}

static void		print_float(t_conv *conv, char *mant, int *exp)
{
	char	*min;
	char	*tmp;
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup(INIT0);
	min = set_min(*exp);
	tmp = mant;
	mant = ft_strjoin("1", mant);
	ft_strdel(&tmp);
	while (i < 24)
	{
		str_mult_by_two(&min);
		if (mant[23 - i] == '1')
			str_addition(&result, min);
		i++;
	}
	ft_strdel(&min);
	tmp = result;
	result = ft_str_notchr(result, '0');
	//ft_strdel(&tmp);
	tmp = result;
	result = round_float(result, conv->prec);
	//ft_strdel(&tmp);
	conv->ret += write(1, result, ft_strlen(result));
	ft_strdel(&result);
}

static void		float_conv(t_conv *conv, float number)
{
	char	*binary;
	char	*mantissa;
	char	*tmp;
	int		exp;
	int		is_neg;

	binary = get_bits(&number);
	is_neg = *binary - 48;
	mantissa = ft_strsub(binary, 9, 23);
	tmp = ft_strsub(binary, 1, 8);
	exp = ft_binatoi(tmp) - 127;
	ft_strdel(&tmp);
	ft_strdel(&binary);
	print_float(conv, mantissa, &exp);
}

void			ft_handle_f(t_conv *conv)
{
	
/*	if (conv->size.l)
		double_conv(conv, va_arg(conv->ap, double));
	else if (conv->size.ll)
		long_double_conv(conv, va_arg(conv->ap, long double));
	else*/
	if (conv->prec == -1)
		conv->prec = 6;
	float_conv(conv, va_arg(conv->ap, double));
}
