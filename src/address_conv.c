/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:12 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/15 14:00:47 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_p(t_conv *conv)
{
	char	*str;

	str = ft_strjoin("0x7fff", ft_llitoa_base(va_arg(conv->ap, int), 16, 1));
	print_sp(conv, str);
	ft_strdel(&str);
}
