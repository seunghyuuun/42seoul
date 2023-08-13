/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:36 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/21 13:53:06 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clearing(t_list **start, void *temp, void (*del)(void *))
{
	t_list	*result;

	result = ft_lstnew(temp);
	if (!result)
	{
		del (temp);
		if (*start)
			ft_lstclear(start, del);
		return (0);
	}
	return (result);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*lsnew;
	t_list	*lsold;
	t_list	*node;

	if (!lst)
		return (0);
	result = 0;
	result = clearing(&result, f(lst->content), del);
	if (!result)
		return (0);
	lsnew = result;
	lsold = lst->next;
	while (lsold)
	{
		node = clearing(&result, f(lsold->content), del);
		if (!node)
			return (0);
		lsnew->next = node;
		lsnew = lsnew->next;
		lsold = lsold->next;
	}
	return (result);
}
