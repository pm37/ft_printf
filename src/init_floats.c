/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:50:02 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/28 14:10:34 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			del_floats(t_conv *conv)
{
	ft_strdel(&FLOATS->binary);
	ft_strdel(&FLOATS->mant);
	ft_strdel(&FLOATS->exp);
	ft_strdel(&RESULT);
	ft_strdel(&FLOATS->min);
	ft_memdel((void **)&conv->floats);
}

char			*init_str(int size, char c)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	i = -1;
	while (++i < size)
		str[i] = '0';
	str[(size - 1) / 2 - 1] = c;
	str[(size - 1) / 2] = '.';
	return (str);
}

static int		init_float_extensions(t_conv *conv)
{
	int		i;
	char	*tmp;

	i = SIZE.lf ? 2 : 1;
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
	FLOATS->f_value.f_num = (float)va_arg(ARG, double);
	FLOATS->binary = get_bits(&FLOATS->f_value.f_num, 4);
	B_SIZE = 274;
	RESULT = init_str(B_SIZE, '0');
}

int				init_floats(t_conv *conv)
{
	conv->prec = conv->prec == -1 ? 6 : conv->prec;
	FLOATS->e_len = SIZE.l ? 11 : 15;
	FLOATS->m_len = SIZE.l ? 52 : 63;
	FLOATS->bias = SIZE.l ? 1023 : 16383;
	if (SIZE.l && (B_SIZE = 2080))
	{
		FLOATS->f_value.d_num = va_arg(ARG, double);
		FLOATS->binary = get_bits(&FLOATS->f_value.d_num, 8);
		RESULT = init_str(B_SIZE, '0');
	}
	else if (SIZE.lf && (B_SIZE = 33000))
	{
		FLOATS->f_value.ld_num = va_arg(ARG, long double);
		FLOATS->binary = get_bits(&FLOATS->f_value.ld_num, 10);
		RESULT = init_str(B_SIZE, '0');
	}
	else
		init_simple_float(conv);
	if (!FLOATS->binary || !RESULT || init_float_extensions(conv) == -1)
	{
		del_floats(conv);
		return (-1);
	}
	return (0);
}
