/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:42:45 by pimichau          #+#    #+#             */
/*   Updated: 2018/11/20 12:14:34 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstadd2(t_list *alst, t_list *new)
{
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}

static t_list	*ft_lstclear(t_list *alst)
{
	t_list	*elem;

	while (alst)
	{
		elem = alst->next;
		free(alst);
		alst = elem;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alst;
	t_list	*new;

	if (!lst || !f || !(alst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	alst = f(lst);
	alst->next = NULL;
	lst = lst->next;
	while (lst)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (ft_lstclear(alst));
		new = f(lst);
		ft_lstadd2(alst, new);
		new->next = NULL;
		lst = lst->next;
	}
	return (alst);
}
