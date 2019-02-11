/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:48:17 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/14 12:31:42 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*v_dst;
	const unsigned char	*v_src;
	size_t				i;
	int					d;

	i = -1;
	v_dst = dst;
	v_src = src;
	d = dst - src;
	if ((d > 0) && (len > (size_t)(d)))
	{
		while (++i < len)
			v_dst[len - 1 - i] = v_src[len - 1 - i];
	}
	else
	{
		while (++i < len)
			v_dst[i] = v_src[i];
	}
	return (dst);
}
