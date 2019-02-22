/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bk_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:44:40 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/22 19:38:55 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>
#include <stdio.h>

char	*get_bits2(long value)
{
	unsigned char	bit;
	int				i;
	int				k;
	char			*tmp;
	char			*binary_form;

	i = 64;
	if (!(tmp = ft_strnew(i)))
		return (NULL);
	k = 0;
	while (i--)
	{
		bit = (value >> i & 1) + 48;
		tmp[k] = bit;
		k++;
	}
	binary_form = ft_strdup(ft_strchr(tmp, '1'));
	ft_strdel(&tmp);
	return (binary_form);
}

void	ft_handle_b(t_conv *conv)
{
	char	*str;
	int		len;

	str = get_bits2(va_arg(conv->ap, ULL));
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
}

void	print_date(t_conv *conv, char *full_date, int len)
{
	if (conv->flag.sharp && conv->prec != 4)
		conv->ret += write(1, full_date + 4, len);
	else if (conv->flag.sharp && conv->prec == 4)
		conv->ret += write(1, full_date + 20, len);
	else
		conv->ret += write(1, full_date, len);
}

void	timestamp_to_date(t_conv *conv)
{
	char	*full_date;
	time_t	timestamp;
	int		len;

	timestamp = va_arg(conv->ap, time_t);
	full_date = ctime(&timestamp);
	len = ft_strlen(full_date);
	len = conv->flag.sharp ? 12 : len - 1;
	len = conv->flag.sharp && conv->prec == 4 ? 4 : len;
	len = conv->flag.sharp && conv->prec == 3 ? 3 : len;
	if (conv->width > len)
	{
		if (!conv->flag.less && !conv->flag.zero)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
		else if (conv->flag.zero && !conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, "0", 1);
	}
	print_date(conv, full_date, len);
	if (conv->width > len && conv->flag.less)
		while (--conv->width >= len)
			conv->ret += write(1, " ", 1);
}

void	date_to_timestamp(t_conv *conv)
{
	struct tm	*time_pointer;
	char		*full_date;
	char		*time_gmt1;

	time_gmt1 = ft_strnew(256);
	if (!(time_pointer = ft_memalloc(sizeof(struct tm))))
		return ;
	full_date = va_arg(conv->ap, char *);
	strptime(full_date, "%b  %d %H:%M:%S %Y", time_pointer);
	strftime(time_gmt1, 256, "%s", time_pointer);
	ft_memdel((void **)&time_pointer);
	conv->ret += write(1, time_gmt1, ft_strlen(time_gmt1));
	ft_strdel(&time_gmt1);
}
