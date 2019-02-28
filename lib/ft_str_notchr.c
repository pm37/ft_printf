/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_notchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:59:51 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/25 22:08:30 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_notchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	return (str + i);
}
