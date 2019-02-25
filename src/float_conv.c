/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:18:08 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/25 19:41:14 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		handle_edge_cases(t_conv *conv)
{
	if (FLOATS->v_exp == FLOATS->bias + 1)
	{
		if (!(ft_strchr(FLOATS->mant, '1')))
			conv->ret += write(1, "inf", 3);
		else
			conv->ret += write(1, "nan", 3);
		return (1);
	}
	if (FLOATS->v_exp == -FLOATS->bias && conv->prec == 0)
	{
		conv->ret += write(1, "0", 1);
		return (1);
	}
	return (0);
}

char		*set_min(t_conv *conv, int exp)
{
	char	*min;
	int		i;

	if (conv->size.l)
		min = ft_strdup(INITD1);
	else if (conv->size.lf)
		min = ft_strdup(INITLD1);
	else
		min = ft_strdup(INITF1);
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

static int		print_float(t_conv *conv)
{
	char	*tmp;
	int		i;
	int		p_max;
	int		p_diff;

	i = -1;
	p_diff = 0;
	while (++i < FLOATS->m_len + 1)
	{
		str_mult_by_two(&FLOATS->min);
		if (FLOATS->mant[FLOATS->m_len - i] == '1')
			str_addition(&FLOATS->result, FLOATS->min);
	}
	tmp = FLOATS->result;
	p_max = ft_strlen(ft_strchr(FLOATS->result, '.') + 1);
	if (conv->prec > p_max)
	{
		conv->prec = p_max;
		p_diff = conv->prec - p_max; 
	}
	if (format_float(conv, ft_str_notchr(FLOATS->result, '0') - 1) == -1)
		return (-1);
	conv->ret += write(1, FLOATS->result, ft_strlen(FLOATS->result));
	while (p_diff--)
		conv->ret += write(1, "0", 1);
	ft_strdel(&tmp);
	return (0);
}

int				handle_f(t_conv *conv)
{
	if (conv->prec == -1)
		conv->prec = 6;
	if (!(conv->floats = ft_memalloc(sizeof(t_float))))
		return (-1);
	if (init_floats(conv) == -1)
		return (-1);
	conv->ret += FLOATS->is_neg ? write(1, "-", 1) : 0;
	if (handle_edge_cases(conv))
		return (0);
	if (print_float(conv) == -1)
	{
		del_floats(conv);
		return (-1);
	}
	del_floats(conv);
	return (0);
}
