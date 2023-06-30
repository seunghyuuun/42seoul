/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:44:02 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/21 13:46:07 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstsep(t_list *lst)
{
	t_list	*result;
	t_list	*temp;

	temp = lst;
	result = temp->next;
	while (result->next)
	{
		temp = result;
		result = result->next;
	}
	temp->next = 0;
	return (result);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while ((*lst)->next)
	{
		temp = lstsep(*lst);
		del(temp->content);
		free (temp);
	}
	temp = *lst;
	del(temp->content);
	free (temp);
	*lst = 0;
}
