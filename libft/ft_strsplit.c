/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:24:34 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/20 11:57:49 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

unsigned int	ft_cw(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb;

	nb = 0;
	if (s[0] != c && s[0])
		nb++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c)
			if (s[i - 1] == c)
				nb++;
		i++;
	}
	return (nb);
}

static char		**ft_clear(char **tab, unsigned int k)
{
	unsigned int	i;

	i = 0;
	while (i <= k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	if (s == NULL || !(tab = (char **)malloc(sizeof(*tab) * (ft_cw(s, c) + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
		{
			if (!(tab[k] = ft_strsub(s, i, j)))
				return (ft_clear(tab, k));
			k++;
			i = i + j - 1;
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}
