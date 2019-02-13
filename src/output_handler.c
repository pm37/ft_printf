/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:03:46 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/13 12:06:14 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_handle_conv(t_conv *conv)
{
	int i;

//			ft_putendl("handle");
	i = 0;
	while (conv->conv_type != conv->type[i])
		i++;
	conv->f[i](conv);
}

int				output_handler(char *fmt, t_conv *conv)
{
//			ft_putendl("conv");
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd' ||
	*fmt == 'i' || *fmt == 'o' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X' ||
	*fmt == 'f')
	{
		conv->conv_type = *fmt;
		ft_handle_conv(conv);
	}
	else
		ft_init_conv(conv);
//	ft_putstr("renvoie length : ");
//	ft_putnbr(conv->length + 1);
//	ft_putendl("");
//	ft_putendl("");

	return (conv->length + 1);
}
