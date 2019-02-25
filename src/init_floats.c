/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:50:02 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/25 22:17:31 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			del_floats(t_conv *conv)
{
	ft_strdel(&FLOATS->binary);
	ft_strdel(&FLOATS->mant);
	ft_strdel(&FLOATS->exp);
	ft_strdel(&FLOATS->result);
	ft_strdel(&FLOATS->min);
	ft_memdel((void **)&conv->floats);
}

static int		init_float_extensions(t_conv *conv)
{
	int		i;
	char	*tmp;

	i = conv->size.lf ? 2 : 1;
	FLOATS->mant = ft_strsub(FLOATS->binary, i + FLOATS->e_len, FLOATS->m_len);
	FLOATS->exp = ft_strsub(FLOATS->binary, 1, FLOATS->e_len);
	if (!FLOATS->mant || !FLOATS->exp)
		return (-1);
	FLOATS->v_exp = ft_binatoi(FLOATS->exp) - FLOATS->bias;
	FLOATS->is_neg = *FLOATS->binary - 48;
	FLOATS->min = set_min(conv, FLOATS->v_exp);
	tmp = FLOATS->mant;
	if (!(FLOATS->mant = ft_strjoin("1", FLOATS->mant)) || !FLOATS->min)
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	return (0);
}

static void		init_simple_float(t_conv *conv)
{
	FLOATS->e_len = 8;
	FLOATS->m_len = 23;
	FLOATS->bias = 127;
	FLOATS->f_value.f_num = (float)va_arg(conv->ap, double);
	FLOATS->binary = get_bits(&FLOATS->f_value.f_num, 4);
	FLOATS->result = ft_strdup(INITF0);
}

int				init_floats(t_conv *conv)
{
	FLOATS->e_len = conv->size.l ? 11 : 15;
	FLOATS->m_len = conv->size.l ? 52 : 63;
	FLOATS->bias = conv->size.l ? 1023 : 16383;
	if (conv->size.l)
	{
		FLOATS->f_value.d_num = va_arg(conv->ap, double);
		FLOATS->binary = get_bits(&FLOATS->f_value.d_num, 8);
		FLOATS->result = ft_strdup(INITD0);
	}
	else if (conv->size.lf)
	{
		FLOATS->f_value.ld_num = va_arg(conv->ap, long double);
		FLOATS->binary = get_bits(&FLOATS->f_value.ld_num, 10);
		FLOATS->result = ft_strdup(INITLD0);
	}
	else
		init_simple_float(conv);
	if (FLOATS->binary == NULL || FLOATS->result == NULL
	|| init_float_extensions(conv) == -1)
	{
		del_floats(conv);
		return (-1);
	}
	return (0);
}
