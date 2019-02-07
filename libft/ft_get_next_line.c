/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:43:24 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/06 15:33:39 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_more(const int fd, char **str)
{
	int		ret;
	int		ft_ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	ft_ret = 1;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = *str;
		if (!(*str = ft_strjoin(*str, buff)))
			ft_ret = 0;
		free(temp);
		if (ft_strchr(*str, '\n') || !(*str))
			break ;
	}
	return (ft_ret);
}

static int	ft_update_line_and_str(char **line, char **str)
{
	int i;

	i = 0;
	while (str[0][i] && str[0][i] != '\n')
		i++;
	if (i == 0)
	{
		if (!(*line = ft_strnew(0)))
			return (0);
	}
	else
	{
		if (!(*line = ft_strsub(*str, 0, i)))
			return (0);
	}
	if (ft_strchr(*str, '\n'))
		return ((*str = ft_strdup(ft_strchr(*str, '\n') + 1)) ? 1 : 0);
	else
		return ((*str = ft_strnew(0)) ? 1 : 0);
}

int			ft_get_next_line(const int fd, char **line)
{
	static char *str[OPEN_MAXI];
	char		*temp;

	if (read(fd, 0, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (str[fd] == NULL)
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	if (!ft_strchr(str[fd], '\n'))
		if (!ft_read_more(fd, &(str[fd])))
			return (-1);
	temp = str[fd];
	if (str[fd][0])
	{
		if (!(ft_update_line_and_str(line, &(str[fd]))))
		{
			free(temp);
			return (-1);
		}
		free(temp);
		return (1);
	}
	return (0);
}
