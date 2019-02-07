/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:00:16 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/16 17:24:49 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*elem;
	t_list	*temp;

	elem = *alst;
	while (elem)
	{
		temp = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = temp;
	}
	*alst = NULL;
}
