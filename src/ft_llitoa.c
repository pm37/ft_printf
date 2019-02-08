/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:08:39 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/08 13:52:09 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_llitoa(long long nb)
{
	int					len;
	unsigned long long	nbr;
	char				*str;
	int					neg;

	neg = (nb < 0) ? 1 : 0;
	nbr = (nb < 0) ? -nb : nb;
//	ft_putnbr(nbr);
//	ft_putendl("");
	len = 1;
	while (nbr /= 10)
		len++;
	nbr = (nb < 0) ? -nb : nb;
//	ft_putnbr(nbr);
//	ft_putendl("");
	if (neg)
		len++;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (0);
	str[len] = '\0';
	//printf("%lld\nfin\n", nbr);
	while (--len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
