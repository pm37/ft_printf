/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:20:17 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/25 15:58:30 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		del_floats(t_conv *conv)
{
	ft_strdel(&FLOATS->binary);
	ft_strdel(&FLOATS->mant);
	ft_strdel(&FLOATS->exp);
	ft_strdel(&FLOATS->result);
	ft_memdel((void **)&conv->floats);
}

void		init_floats(t_conv *conv)
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
	{
		FLOATS->e_len = 8;
		FLOATS->m_len = 23;
		FLOATS->bias = 127; 
		FLOATS->f_value.f_num = (float)va_arg(conv->ap, double);
		FLOATS->binary = get_bits(&FLOATS->f_value.f_num, 4);
		FLOATS->result = ft_strdup(INITF0);
	}
}

void		ft_init_conv(t_conv *conv)
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

void		ft_init_fp(t_conv *conv)
{
	conv->ret = 0;
	init_types(conv);
	conv->f[1] = ft_handle_s;
	conv->f[2] = ft_handle_p;
	conv->f[3] = ft_handle_di;
	conv->f[4] = ft_handle_di;
	conv->f[5] = ft_handle_o;
	conv->f[6] = ft_handle_u;
	conv->f[7] = ft_handle_xx;
	conv->f[8] = ft_handle_xx;
	conv->f[9] = ft_handle_f;
	conv->f[10] = ft_handle_b;
	conv->f[11] = timestamp_to_date;
	conv->f[12] = date_to_timestamp;
}
