/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:07:19 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/13 13:36:02 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_f(t_conv *conv)
{
	char	*str;

	if (conv->prec == -1)
		conv->prec = 6;
	str = ft_strdup(ft_ftoa(va_arg(conv->ap, double), conv->prec));
	ft_handle_di_p(conv, str);
}
