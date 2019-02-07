/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:49:18 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/15 16:59:08 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		n;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	n = (int)ft_strlen(s);
	while (n > 0 && (s[n - 1] == ' ' || s[n - 1] == '\t' || s[n - 1] == '\n'))
		n--;
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	str[n] = '\0';
	while (n > 0)
	{
		str[n - 1] = s[n - 1];
		n--;
	}
	return (str);
}
