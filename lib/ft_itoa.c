/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:00:33 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/08 14:05:37 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_cl(int n)
{
	long	v;
	int		l;

	v = n;
	l = 1;
	if (n < 0)
	{
		v = -v;
		l++;
	}
	while (v > 9)
	{
		v /= 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		l;
	int		i;
	long	v;

	l = ft_cl(n);
	if (!(str = (char *)malloc(sizeof(*str) * (l + 1))))
		return (NULL);
	str[l] = '\0';
	if (n == 0)
		str[0] = '\0';
	v = n;
	if (v < 0)
		v = -v;
	i = 0;
	while (l - 1 - i >= 0)
	{
		str[l - 1 - i] = (v % 10) + 48;
		v /= 10;
		i++;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
