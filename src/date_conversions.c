/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:34:23 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/26 10:40:29 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

void	print_date(t_conv *conv, char *full_date, int len)
{
	if (conv->flag.sharp && conv->prec != 4)
		conv->ret += write(1, full_date + 4, len);
	else if (conv->flag.sharp && conv->prec == 4)
		conv->ret += write(1, full_date + 20, len);
	else
		conv->ret += write(1, full_date, len);
}

int		timestamp_to_date(t_conv *conv)
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
	return (0);
}

int		date_to_timestamp(t_conv *conv)
{
	struct tm	*time_pointer;
	char		*full_date;
	char		*time_gmt1;
	int		len;

	if (!(time_gmt1 = ft_strnew(256)))
		return (-1);
	if (!(time_pointer = ft_memalloc(sizeof(struct tm))))
	{
		ft_strdel(&time_gmt1);
		return (-1);
	}
	full_date = va_arg(conv->ap, char *);
	strptime(full_date, "%b  %d %H:%M:%S %Y", time_pointer);
	strftime(time_gmt1, 256, "%s", time_pointer);
	ft_memdel((void **)&time_pointer);
	len = ft_strlen(time_gmt1);
	if (conv->width > len)
	{
		if (!conv->flag.less && !conv->flag.zero)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
		else if (conv->flag.zero && !conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, "0", 1);
	}
	conv->ret += write(1, time_gmt1, len);
	if (conv->width > len && conv->flag.less)
		while (--conv->width >= len)
			conv->ret += write(1, " ", 1);
	ft_strdel(&time_gmt1);
	return (0);
}
