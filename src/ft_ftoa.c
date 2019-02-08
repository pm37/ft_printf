/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:08:39 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/08 13:54:35 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

char	*ft_get_f_dec2(double nb, int dec)
{
	char		*str;
	char		*str_tmp;
	int			i;
	int			len;

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
char	*ft_get_f_int(double nb)
{
	char	*str;
	char	*str_tmp;
	int		i;
	double	nbr;

	nbr = nb;
	i = 0;
	str = ft_strnew(0);
	while (nb > 1)
	{
		nb /= 10;
		i++;
	}
	//str = ft_llitoa(nb);
	//printf("\ni vaut :%d\n", i);
	//printf("nb vaut : %f", nb);	
	//nbr = nbr - ((long long)nb * 100.0);
	//printf("nbr vaut : %f", nbr);	
	//nb *= 100;
	//printf("nb vaut : %f", nb);	
	while (i--)
	{
		nb = nb * 10;
		str_tmp = ft_llitoa(nb);
		str = ft_strjoin(str, str_tmp);
		nb = nb - (long)nb;
	}
	//str = ft_strjoin(str, ft_get_f_dec2(nb, i));
	
	return (str);
}
char	*ft_ftoa(double nb, int dec)
{
	int					len;
	char				*str;
	char				*str_int;
	int					neg;
	int					i;

	i = 1;
	if (!dec)
		return (ft_strdup(ft_itoa((int)nb)));
	neg = (nb < 0) ? 1 : 0;
	str = ft_get_f_dec(nb, dec + 1);
//	printf("\n et un de plus : %f\n", nb);
	str_int = ft_get_f_int(nb);
	return (ft_strjoin(str_int, ft_strjoin(".", str)));
}
