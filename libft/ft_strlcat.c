/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:19:34 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/13 12:32:55 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(dst);
	if (n >= size)
		return (size + ft_strlen(src));
	while (i < (size - n - 1) && src[i])
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (n + ft_strlen(src));
}
