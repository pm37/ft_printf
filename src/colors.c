/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:14:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/02/21 16:20:14 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_color(char c, char *style, int *i)
{
	if (ft_strequ(style, BLACK) && (*i += ft_strlen(BLACK) - 1))
		ft_putstr("\033[30m");
	else if (ft_strequ(style, RED) && (*i += ft_strlen(RED) - 1))
		ft_putstr("\033[31m");
	else if (ft_strequ(style, GREEN) && (*i += ft_strlen(GREEN) - 1))
		ft_putstr("\033[32m");
	else if (ft_strequ(style, YELLOW) && (*i += ft_strlen(YELLOW) - 1))
		ft_putstr("\033[33m");
	else if (ft_strequ(style, BLUE) && (*i += ft_strlen(BLUE) - 1))
		ft_putstr("\033[34m");
	else if (ft_strequ(style, PURPLE) && (*i += ft_strlen(PURPLE) - 1))
		ft_putstr("\033[35m");
	else if (ft_strequ(style, CYAN) && (*i += ft_strlen(CYAN) - 1))
		ft_putstr("\033[36m");
	else if (ft_strequ(style, BOLD) && (*i += ft_strlen(BOLD) - 1))
		ft_putstr("\033[1m");
	else if (ft_strequ(style, UNDERLINED) && (*i += ft_strlen(UNDERLINED) - 1))
		ft_putstr("\033[4m");
	else if (ft_strequ(style, NC) && (*i += ft_strlen(NC) - 1))
		ft_putstr("\033[0m");
	else if (write(1, &c, 1))
		return (0);
	return (1);
}

void	color_check(t_conv *conv, const char *format, int *i)
{
	int		stop;

	stop = ft_strchr_index(format, '}');
	if (!(conv->style = ft_strsub(format, 0, stop + 1)))
		return ;
	apply_color(*format, conv->style, i);
	if (conv->style)
		ft_strdel(&conv->style);
}