/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:18:08 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/26 18:06:33 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		long_double_edge_cases(t_conv *conv)
{
	if (!ft_strchr(FLOATS->exp, '0'))
	{
		ft_strdel(&RESULT);
		if (FLOATS->binary[16] == '0')
		{
			if (FLOATS->binary[17] == '0'
			&& !ft_strchr(FLOATS->binary + 18, '1'))
				RESULT = ft_strdup("inf");
			else if (FLOATS->binary[17] == '1')
				RESULT = ft_strdup("nan");
		}
		else if (FLOATS->binary[16] == '1' && FLOATS->binary[17] == '0')
		{
			if (!ft_strchr(FLOATS->binary + 18, '1'))
				RESULT = ft_strdup("inf");
			else
				RESULT = ft_strdup("nan");
		}
		else if (FLOATS->binary[16] == '1' && FLOATS->binary[17] == '1')
			RESULT = ft_strdup("nan");
		LEN = 3;
		EDGE = 1;
		return (!RESULT ? -1 : 1);
	}
	return (0);
}

static int		handle_edge_cases(t_conv *conv)
{
	if (conv->size.lf)
		return (long_double_edge_cases(conv));
	else
	{
		if (FLOATS->v_exp == FLOATS->bias + 1)
		{
			ft_strdel(&RESULT);
			if (!(ft_strchr(FLOATS->mant + 1, '1')))
				RESULT = ft_strdup("inf");
			else
				RESULT = ft_strdup("nan");
			LEN = 3;
			EDGE = 1;
			return (!RESULT ? -1 : 1);
		}
		if (FLOATS->v_exp == -FLOATS->bias && conv->prec == 0)
		{
			ft_strdel(&RESULT);
			RESULT = ft_strdup("0");
			LEN = 1;
			EDGE = 1;
			return (!RESULT ? -1 : 1);
		}
	}
	return (0);
}

char			*set_min(t_conv *conv, int exp)
{
	char	*min;
	int		i;

	if (conv->size.l)
		min = init_str(315, '1');
	else if (conv->size.lf)
		min = init_str(10001, '1');
	else
		min = init_str(101, '1');
	if (!min)
		return (NULL);
	i = -1;
	if (exp >= FLOATS->m_len)
		while (++i < exp - FLOATS->m_len - 1)
			str_mult_by_two(&min);
	else
		while (++i < FLOATS->m_len - exp + 1)
			str_div_by_two(&min);
	return (min);
}

static int		format_result(t_conv *conv)
{
	char	*tmp;
	int		i;
	int		p_max;

	i = -1;
	while (++i < FLOATS->m_len + 1)
	{
		str_mult_by_two(&FLOATS->min);
		if (FLOATS->mant[FLOATS->m_len - i] == '1')
			str_addition(&RESULT, FLOATS->min);
	}
	tmp = RESULT;
	p_max = ft_strlen(ft_strchr(RESULT, '.') + 1);
	if (conv->prec > p_max && (P_DIFF = conv->prec - p_max))
		conv->prec = p_max;
	if (format_float(conv, ft_str_notchr(RESULT, '0') - 1) == -1)
		return (-1);
	LEN = ft_strlen(RESULT);
	ft_strdel(&tmp);
	return (0);
}

int				handle_f(t_conv *conv)
{
	if (!(conv->floats = ft_memalloc(sizeof(t_float))))
		return (-1);
	if (init_floats(conv) == -1)
		return (-1);
	if ((!conv->size.lf && FLOATS->is_neg)
	|| (conv->size.lf && FLOATS->binary[0] == '1') || FLAG.plus)
		SIGN = 1;
	if (handle_edge_cases(conv))
	{
		print_float(conv);
		del_floats(conv);
		return (0);
	}
	if (format_result(conv) == -1)
	{
		del_floats(conv);
		return (-1);
	}
	print_float(conv);
	del_floats(conv);
	return (0);
}
