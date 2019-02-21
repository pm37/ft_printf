/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:08:39 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/21 14:23:33 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_zero(int prec)
{
	char	*dec_part;
	int		i;

	if (!(dec_part = (char *)malloc(sizeof(char) * (prec + 1))))
		return (0);
	dec_part[prec] = '\0';
	i = 0;
	while (i < prec)
	{
		dec_part[i] = '0';
		i++;
	}
	return (dec_part);
}

static char	*get_dec_part(double nb, int prec)
{
	char	*dec_part;
	char	*dec_tmp;
	char	*tmp;
	int		len;

	if (nb > 9223372036854775807.0)
		return (ft_zero(prec));
	dec_part = ft_strnew(0);
	while (prec + 1 >= 1)
	{
		nb = (nb - (long long)nb) * 10;
		dec_tmp = ft_itoa(nb);
		tmp = dec_part;
		dec_part = ft_strjoin(dec_part, dec_tmp);
		free(tmp);
		free(dec_tmp);
		prec--;
	}
	len = ft_strlen(dec_part);
	if (len - 2 >= 0)
		if (dec_part[len - 1] > '4')
			dec_part[len - 2]++;
	dec_part[len - 1] = '\0';
	return (dec_part);
}

static char	*get_int_part(double nb)
{
	int			i;
	char		*int_part;
	char		*tmp;

	i = 0;
	while (nb > 9223372036854775807.0)
	{
		nb /= 10;
		i++;
	}
	int_part = ft_llitoa(nb);
	if (i)
	{
		tmp = int_part;
		int_part = ft_strjoin(int_part, get_dec_part(nb, i));
		free(tmp);
	}
	return (int_part);
}

char	*ft_lftoa(double nb, int prec)
{
	char	*result;
	char	*int_part;
	char	*tmp;
	int		i;

	result = 0;
	i = 1;
	if (prec > 0)
	{
		result = get_dec_part(nb, prec);
		tmp = result;
		result = ft_strjoin(".", result);
		free(tmp);
	}
	else
		result = ft_strnew(0);
	int_part = get_int_part(nb);
	tmp = result;
	result = ft_strjoin(int_part, result);
	free(int_part);
	free(tmp);
	return (result);
}
