/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bk_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:44:40 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/26 10:40:14 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_simple_binary(t_conv *conv, char **str)
{
	t_ftype	type;

	if (conv->size.l || conv->size.ll )
	{
		type.l_num = va_arg(conv->ap, long);
		*str = get_bits(&type.l_num,  8);
	}
	else if (conv->size.h) 
	{
		type.i_num = va_arg(conv->ap, int);
		*str = get_bits(&type.i_num, 2); 
	}
	else if (conv->size.hh)
	{
		type.i_num = va_arg(conv->ap, int);
		*str = get_bits(&type.i_num, 1);
	}
	else
	{
		type.i_num = va_arg(conv->ap, int);
		*str = get_bits(&type.i_num, 4);
	}
	if (*str == NULL)
		return (-1);
	return (0);
}

static char	*get_binary(t_conv *conv)
{
	char	*str;

	if (conv->flag.sharp)
	{
		if (!(conv->floats = ft_memalloc(sizeof(t_float))))
			return (NULL);
		if (init_floats(conv) == -1)
			return (NULL);
		if (!(str = ft_strdup(FLOATS->binary)))
			return (NULL);
		del_floats(conv);
	}
	else if (get_simple_binary(conv, &str) == -1)
		return (NULL);
	if (!str)
		return (NULL);
	return (str);
}

int		handle_b(t_conv *conv)
{
	int	len;
	char	*str;

	if (!(str = get_binary(conv)))
		return (-1);
	len = ft_strlen(str);
	if (conv->width > len)
	{
		if (!conv->flag.less && !conv->flag.zero)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
		else if (conv->flag.zero && !conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, "0", 1);
	}
	conv->ret += write(1, str, len);
	if (conv->width > len && conv->flag.less)
		while (--conv->width >= len)
			conv->ret += write(1, " ", 1);
	ft_strdel(&str);
	return (0);
}


