/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:20:17 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/25 18:52:14 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (-1);
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

void			init_conv(t_conv *conv)
{
	conv->size.h = 0;
	conv->size.hh = 0;
	conv->size.l = 0;
	conv->size.ll = 0;
	conv->size.j = 0;
	conv->size.lf = 0;
	conv->length = 0;
	conv->prec = -1;
	conv->width = -1;
	conv->flag.zero = 0;
	conv->flag.space = 0;
	conv->flag.sharp = 0;
	conv->flag.plus = 0;
	conv->flag.less = 0;
	conv->style = NULL;
}

static void	init_types(t_conv *conv)
{
	conv->type[0] = 'c';
	conv->type[1] = 's';
	conv->type[2] = 'p';
	conv->type[3] = 'd';
	conv->type[4] = 'i';
	conv->type[5] = 'o';
	conv->type[6] = 'u';
	conv->type[7] = 'x';
	conv->type[8] = 'X';
	conv->type[9] = 'f';
	conv->type[10] = 'b';
	conv->type[11] = 'k';
	conv->type[12] = 'K';
}

void		init_fp(t_conv *conv)
{
	conv->ret = 0;
	init_types(conv);
	conv->f[0] = print_c;
	conv->f[1] = handle_s;
	conv->f[2] = handle_p;
	conv->f[3] = handle_di;
	conv->f[4] = handle_di;
	conv->f[5] = handle_o;
	conv->f[6] = handle_u;
	conv->f[7] = handle_xx;
	conv->f[8] = handle_xx;
	conv->f[9] = handle_f;
	conv->f[10] = handle_b;
	conv->f[11] = timestamp_to_date;
	conv->f[12] = date_to_timestamp;
}
