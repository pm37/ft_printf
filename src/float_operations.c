/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:40:48 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/24 04:00:11 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_float(char *number, int ret)
{
	int	len;
	int	i;

	len = ft_strlen(number);
	i = len;
	while (i--)
	{
		if (number[i] - 48 + ret > 9 && number[i] != '.')
		{
			number[i] = '0';
			ret = 1;
		}
		else if (number[i] != '.')
		{
			number[i] = number[i] + ret;
			ret = 0;
		}
	}
}

char	*format_float(char *number, int precision)
{
	int		len;
	char	*result;
	char	*tmp;
	int	ret;
	int	i;

	ret = 0;
	if (precision > 49)
		precision = 49;
	len = ft_strchr_index(number, '.') + 1 + precision;
	len += precision == 0 ? -1 : 0;
	if ((number[len] == '.' && number[len + 1] - 48 >= 5)
	|| (number[len] != '.' && number[len] - 48 >= 5))
		ret = 1;
	result = ft_strsub(number, 0, len);
	if (ret)
		round_float(result, ret);
	tmp = result;
	i = *(ft_str_notchr(result, '0')) == '.' ? 1 : 0;
	result = ft_strdup(ft_str_notchr(result, '0') - i);
	ft_strdel(&tmp);
	return (result);
}

void	str_mult_by_two(char **str)
{
	int i;
	int len;
	int	ret = 0;

	i = 0;
	len = ft_strlen(*str);
	while (i < len)
	{
		if (str[0][len - 1 - i] < '5' && str[0][len - 1 - i] >= '0')
		{
			str[0][len - 1 - i] = str[0][len - 1 - i] + str[0][len - 1 - i] - 48 + ret;
			ret = 0;
		}
		else if (str[0][len - 1 - i] <= '9' && str[0][len - 1 - i] >= '5')
		{
			str[0][len - 1 - i] = ((str[0][len - 1 - i] - 48) * 2) % 10 + 48 + ret;
			ret = 1;
		}
		i++;
	}
}

void	str_div_by_two(char **str)
{
	int len;
	int	tmp;
	int	i = 0;
	int	ret = 0;

	len = ft_strlen(*str);
	while (i < len)
	{
		if (str[0][i] != '.')
		{
			tmp = (str[0][i] - 48) % 2;
			str[0][i] = ((str[0][i] - 48) / 2 + ret) + 48;
			ret = tmp == 0 ? 0 : 5;
		}
		i++;
	}
}

void	str_addition(char **result, char *add)
{
	int i;
	int len;
	int j;
	int	ret = 0;

	i = 0;
	len = ft_strlen(*result);
	while (i < len)
	{
		j = len - 1 - i;
		if (result[0][j] == '.')
			result[0][j] = '.';
		else if (result[0][j] + add[j] - 48 + ret <= '9')
		{
			result[0][j] += add[j] - 48 + ret;
			ret = 0;
		}
		else if (result[0][j] + add[j] - 48 + ret > '9')
		{
			result[0][j] = (result[0][j] - 48 + add[j] - 48 + ret) % 10 + 48;
			ret = 1;
		}
		i++;
	}
}
