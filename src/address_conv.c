/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:12 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/19 17:51:12 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_p(t_conv *conv)
{
	char	*str;
	char	*tmp;

	tmp = ft_ullitoa_base((uintptr_t)va_arg(conv->ap, void *), 16);
	str = ft_strjoin("0x", tmp);
	print_sp(conv, str);
	ft_strdel(&str);
}
