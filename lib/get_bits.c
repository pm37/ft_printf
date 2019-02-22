/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:31:38 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/22 17:34:25 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_bits(void *octet)
{
	int				i;
	int				j;
	unsigned char	bit;
	int				*ptr;
	char			*str;


	str = (char *)malloc(sizeof(*str) * 33);
	ptr = octet;
	i = 32;
	j = 0;
	while (i--)
	{
		bit = (*ptr >> i & 1) + '0';
		str[j] = bit;
		j++;
	}
	str[j] = '\0';
	return (str);
}
