/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:18:08 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/25 15:57:35 by pimichau         ###   ########.fr       */
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

static char		*set_min(t_conv *conv, int exp)
{
	char	*min;
	int		i;

	if (conv->size.l)
		min = ft_strdup(INITD1);
	else if (conv->size.lf)
		min = ft_strdup(INITLD1);
	else
		min = ft_strdup(INITF1);
	i = -1;
	if (exp >= FLOATS->m_len)
		while (++i < exp - FLOATS->m_len - 1)
			str_mult_by_two(&min);
	else
		while (++i < FLOATS->m_len - exp + 1)
			str_div_by_two(&min);
	return (min);
}

static void		print_float(t_conv *conv)
{
	char	*min;
	char	*tmp;
	int		i;

	i = 0;
	min = set_min(conv, FLOATS->v_exp);
	tmp = FLOATS->mant;
	FLOATS->mant = ft_strjoin("1", FLOATS->mant);
	ft_strdel(&tmp);
	while (i < FLOATS->m_len + 1)
	{
		str_mult_by_two(&min);
		if (FLOATS->mant[FLOATS->m_len - i] == '1')
			str_addition(&FLOATS->result, min);
		i++;
	}
	ft_strdel(&min);
	tmp = FLOATS->result;
	FLOATS->result = format_float(ft_str_notchr(FLOATS->result, '0') - 1, conv->prec);
	conv->ret += write(1, FLOATS->result, ft_strlen(FLOATS->result));
	ft_strdel(&tmp);
}

static void		float_conv(t_conv *conv)
{
	int		i;

	i = conv->size.lf ? 2 : 1;
	FLOATS->is_neg = *FLOATS->binary - 48;
	FLOATS->mant = ft_strsub(FLOATS->binary, i + FLOATS->e_len, FLOATS->m_len);
	FLOATS->exp = ft_strsub(FLOATS->binary, 1, FLOATS->e_len);
	FLOATS->v_exp = ft_binatoi(FLOATS->exp) - FLOATS->bias;
	conv->ret += FLOATS->is_neg ? write(1, "-", 1) : 0;
	if (handle_edge_cases(conv))
		return ;
	print_float(conv);
}

void			ft_handle_f(t_conv *conv)
{
	if (conv->prec == -1)
		conv->prec = 6;
	if (!(conv->floats = ft_memalloc(sizeof(t_float))))
		return ;
	init_floats(conv);
	float_conv(conv);
	del_floats(conv);
}
