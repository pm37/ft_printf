/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:56 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/15 13:09:31 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_sp_p(t_conv *conv, char *output)
{
	size_t	len;
	int		i;

	len = ft_strlen(output);
	if (conv->prec != -1 && conv->prec < len)
	{
		i = (int)conv->prec;
		output[i] = '\0';
	}
	len = ft_strlen(output);
	if (conv->width > len)
		if (!conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
	conv->ret += write(1, output, len);
	if (conv->width > len)
		if (conv->flag.less)
			while (--conv->width >= len)
				conv->ret += write(1, " ", 1);
}

void		ft_handle_di_p(t_conv *conv, char *output)
{
	int		len;
	int		pr;

	prec = conv->prec + conv->flag.plus;
	len = ft_strlen(output) + conv->flag.plus;
	//si largeur est > a la prec + 1 (si flag.plus) et qu'on doit imprimer avant (!flag.less)
	if (conv->width > ft_max(prec, len) && !conv->flag.less)
		while (--conv->width >= ft_max(conv->prec, len))
			conv->ret += write(1, " ", 1);
	if (conv->flag.plus)
		conv->ret += write(1, "+", 1);
	if (conv->width > ft_max(prec, len) && !conv->flag.less && conv->flag.zero && conv->prec == -1)
		while (--conv->width >= ft_max(conv->prec, len))
			conv->ret += write(1, "0", 1);
	if (conv->prec != -1 && len < conv->prec)
		while (--conv->prec >= len)
			conv->ret += write(1, "0", 1);
	conv->ret += write(1, output, ft_strlen(output));
	if (conv->width > ft_max(prec, len) && conv->flag.less)
		while (--conv->width >= prec && conv->width >= len)
			conv->ret += write(1, " ", 1);
	ft_strdel(&output);
}

void	ft_handle_x_p(t_conv *conv, char *output)
{
	int		len;
	int		prec;

	prec = conv->prec + conv->flag.sharp * 2;
	len = ft_strlen(output) + conv->flag.sharp * 2;
	//width : imprimer des espaces si !'-' en prenant en compte les espaces occupes si '#' & precision
	if (conv->width > prec && conv->width > len && !conv->flag.less)
			while (--conv->width >= conv->prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
	//flag '#'
	if (conv->flag.sharp)
		conv->ret += write(1, "0x", 2);
	//width & flag '0' : imprimer des '0' si la precision et le flag '-' ne sont pas definis
	if (conv->width > prec && conv->width > len && 
	!conv->flag.less && conv->flag.zero && conv->prec == -1)
		while (--conv->width >= len && conv->width >= len)
			conv->ret += write(1, "0", 1);
	//imprimer des '0' selon la precision precision
	if (conv->prec != -1 && len < conv->prec)
			while (--conv->prec >= len)
				conv->ret += write(1, "0", 1);
	//imprimer output
	conv->ret += write(1, output, ft_strlen(output));
	//width : imprimer des espaces si '-'
	if (conv->width > prec + conv->flag.sharp * 2 && conv->width > len && conv->flag.less)
			while (--conv->width >= prec && conv->width >= len)
				conv->ret += write(1, " ", 1);
	ft_strdel(&output);
}

void		ft_handle_c(t_conv *conv)
{
	//debug
	//ft_putendl("entree dans ft_hand_c");
	if (conv->width != 0)
		if (!conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
	ft_putchar(va_arg(conv->ap, int));
	conv->ret++;
	//debug
	//printf("apres conv->ret++ :%d\n", conv->ret);
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width)
				conv->ret += write(1, " ", 1);
}

void		ft_handle_s(t_conv *conv)
{
	char	*str;

	str = ft_strdup(va_arg(conv->ap, char *));
	ft_handle_sp_p(conv, str);
}
