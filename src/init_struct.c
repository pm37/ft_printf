/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:20:17 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/13 15:42:05 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_conv(t_conv *conv)
{
	conv->size.h = 0;
	conv->size.hh = 0;
	conv->size.l = 0;
	conv->size.ll = 0;
	conv->length = 0;
	conv->prec = -1;
	conv->width = -1;
}

void	ft_init_fp(t_conv *conv)
{
	conv->f[0] = ft_handle_c;
	conv->type[0] = 'c';
	conv->f[1] = ft_handle_s;
	conv->type[1] = 's';
	conv->f[2] = ft_handle_p;
	conv->type[2] = 'p';
	conv->f[3] = ft_handle_di;
	conv->type[3] = 'd';
	conv->f[4] = ft_handle_di;
	conv->type[4] = 'i';
	conv->f[5] = ft_handle_o;
	conv->type[5] = 'o';
	conv->f[6] = ft_handle_u;
	conv->type[6] = 'u';
	conv->f[7] = ft_handle_x;
	conv->type[7] = 'x';
	conv->f[8] = ft_handle_X;
	conv->type[8] = 'X';
	conv->f[9] = ft_handle_f;
	conv->type[9] = 'f';
}
