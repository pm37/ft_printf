/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:55:38 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/27 16:57:18 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_float_len(char *str)
{
	int		last_index;
	int		first_index;

	first_index = ft_str_notchr_index(str, '0', '.');
	last_index = ft_strr_notchr_index(str, '0', '.');
	return (last_index - first_index + 1);
}
