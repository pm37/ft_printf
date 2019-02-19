/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:46:15 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/11 20:48:25 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ullitoa_base(unsigned long long nb, int base, int lowercase)
{
	char					*str;
	int						len;
	unsigned long long		nbr;
	
	if (base < 2 || base > 16)
		return (0);
	if (base == 10)
		return (ft_itoa(nb));
	len = 1;
	nbr = nb;
	while (nbr /= base)
		len++;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (0);
	str[len] = '\0';
	while (--len >= 0)
	{
		if (nb % base > 9 && lowercase)
			str[len] = (nb % base) % 10 + 'a';
		else if (nb % base > 9 && !lowercase)
			str[len] = (nb % base) % 10 + 'A';
		else
			str[len] = (nb % base) + '0';
		nb /= base;
	}
	return (str);
}
