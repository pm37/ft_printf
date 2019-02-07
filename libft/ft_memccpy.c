/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:30:27 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/14 18:21:11 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char		*v_dst;
	const unsigned char	*v_src;
	size_t				i;

	i = 0;
	v_dst = dst;
	v_src = src;
	while (i < n)
	{
		v_dst[i] = v_src[i];
		i++;
		if (v_dst[i - 1] == (unsigned char)(c))
			return ((void *)&v_dst[i]);
	}
	return (NULL);
}
