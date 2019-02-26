/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:56:18 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/26 17:42:30 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_flags_before(t_conv *conv)
{
	if (FLAG.space && ((ft_strequ(RESULT, "nan") && !FLAG.less) || !SIGN)
	&& !ft_strequ(RESULT, "inf"))
	{
		conv->ret += write(1, " ", 1);
		if ((!ft_strequ(RESULT, "nan") && FLAG.less))
			--conv->width;
	}
	if (conv->width > LEN + P_DIFF + SIGN && (!FLAG.zero || EDGE) && !FLAG.less)
		while (--conv->width > LEN + P_DIFF + SIGN - EDGE)
			conv->ret += write(1, " ", 1);
	if (SIGN && !ft_strequ(RESULT, "nan"))
	{
		if ((!SIZE.lf && IS_NEG) || (SIZE.lf && *FLOATS->binary == '1'))
			conv->ret += write(1, "-", 1);
		else
			conv->ret += write(1, "+", 1);
	}
	if (conv->width > LEN + P_DIFF + SIGN && FLAG.zero && !FLAG.less && !EDGE)
		while (--conv->width > LEN + P_DIFF + SIGN)
			conv->ret += write(1, "0", 1);
}

void			print_float(t_conv *conv)
{
	print_flags_before(conv);
	conv->ret += write(1, RESULT, LEN);
	while (P_DIFF--)
		conv->ret += write(1, "0", 1);
	if (conv->width > LEN + P_DIFF + SIGN && FLAG.less)
	{
		FLAG.less = ft_strequ(RESULT, "nan") ? 1 : 0;
		while (--conv->width + FLAG.less > LEN + P_DIFF + SIGN)
			conv->ret += write(1, " ", 1);
	}
}
