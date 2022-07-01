/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:37:37 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/12 21:24:22 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*start;

	if (!f ||!lst)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (new_list);
	start = new_list;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&start, ft_lstnew(f(lst->content)));
		if (!new_list->next)
			ft_lstclear(&start, del);
		lst = lst->next;
		new_list = new_list->next;
	}
	return (start);
}
