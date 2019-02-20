/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:08:39 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/15 11:59:46 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
char	*get_dec_part(long double nb, int prec)
{
	char		*dec_part;
	char		*dec_tmp;
	int			len;

	str = ft_strnew(0);
	while (prec >= 1)
	{
		nb = (nb - (long long)nb) * 10;
		dec_tmp = ft_itoa(nb);
		dec_part = ft_strjoin(dec_part, dec_tmp);
		prec--;
	}
	len = ft_strlen(dec_part);
	if (len - 2 >= 0)
		if (dec_part[len - 1] > '4')
			dec_part[len - 2]++;
	dec_part[len - 1] = '\0';
	return (dec_part);
}

char	*ft_get_f_dec2(double nb, int dec)
{
	char		*str;
	char		*str_tmp;
	int			i;

	str = ft_strnew(0);
	i = dec;
	while (i > 1)
	{
		nb = (nb - (long long)nb) * 10;
		str_tmp = ft_llitoa(nb);
		str = ft_strjoin(str, str_tmp);
		i--;
	}
	return (str);
}
char	*get_int_part(long double nb)
{
	//long long n;
	int				i;
	char			*int_part;

	i = 0;
	while (nb > 9223372036854775807.0)
	{
		nb /= 10;
		i++;
	}
	int_part = ft_llitoa((long long)nb);
	if (i)
		int_part = ft_strjoin(int_part, get_dec_part(nb, i + 1));
	return (int_part);
}
char	*ft_lftoa(long double nb, int prec)
{
	char				*dec_part;
	char				*int_part;
	int					neg;
	int					i;

	i = 1;
	if (!prec)
		return (ft_llitoa((long long)nb));
	neg = (nb < 0) ? 1 : 0;
	dec_part = get_dec_part(nb, prec + 1);
//	printf("\n et un de plus : %f\n", nb);
	int_part = get_int_part(nb);
	printf("int_part: %s\ndec_part: %s\n", int_part, dec_part);
	return (ft_strjoin(int_part, ft_strjoin(".", dec_part)));
}
