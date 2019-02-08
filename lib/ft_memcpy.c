/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:09:08 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/20 11:56:00 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*v_dst;
	const unsigned char	*v_src;
	size_t				i;

	i = 0;
	if (!dst && !src && n > 0)
		return (NULL);
	v_dst = dst;
	v_src = src;
	while (i < n)
	{
		v_dst[i] = v_src[i];
		i++;
	}
	return (dst);
}
