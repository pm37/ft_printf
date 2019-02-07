/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:08:39 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/07 14:51:26 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(double nb, int dec)
{
	int					len;
	char				*str;
	int					neg;
	int					i;

	i = 1;
	if (!dec)
		return (ft_strdup(ft_itoa((int)nb)));
	neg = (nb < 0) ? 1 : 0;
	str = ft_get_f_dec(nb, dec + 1);
	return (ft_strjoin(ft_llitoa((long long)nb), ft_strjoin(".", str)));
}

char	*ft_get_f_dec(double nb, int dec)
{
	char		*str;
	char		*str_tmp;
	int			i;
	int			len;

	str = ft_strnew(0);
	i = dec;
	while (i >= 1)
	{
		nb = (nb - (long long)nb) * 10;
		str_tmp = ft_llitoa(nb);
		str = ft_strjoin(str, str_tmp);
		i--;
	}
	len = ft_strlen(str);
	if (len - 2 >= 0)
		if (str[len - 1] > '4')
			str[len - 2]++;
	str[len - 1] = '\0';
	return (str);
}
