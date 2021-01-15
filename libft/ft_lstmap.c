/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:15:14 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/18 16:30:30 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *list)
{
	if (list->next)
		ft_free(list->next);
	free(list->content);
	free(list);
	list = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *new;
	t_list *lol;

	if (!lst || !(f))
		return (NULL);
	list = f(lst);
	new = ft_lstnew(list->content, list->content_size);
	if (!new)
		return (NULL);
	lol = new;
	while (lst->next)
	{
		lst = lst->next;
		list = f(lst);
		lol->next = ft_lstnew(list->content, list->content_size);
		if (!(lol->next))
		{
			ft_free(new);
			return (NULL);
		}
		lol = lol->next;
	}
	return (new);
}
