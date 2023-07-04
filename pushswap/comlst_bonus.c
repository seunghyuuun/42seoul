/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comlst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:51:35 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/04 20:27:59 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	checkcmd(char *cmd)
{
	int	first;

	first = cmd[0];
	if (!(ft_strchr("psr", first)))
		return (0);
	if (cmd[1] != 'a' && cmd[1] != 'b' && cmd[1] != first)
		return (0);
	if (cmd[2] == '\n' && !cmd[3])
		return (first);
	if (cmd[2] != 'a' && cmd[2] != 'b' && cmd[2] != first)
		return (0);
	if (cmd[3] == '\n' && !cmd[4])
		return (first);
	return (0);
}

t_list	*commandset(int *errorcheck)
{
	t_list	*result;
	t_list	*temp;
	char	*cmd;

	result = 0;
	cmd = get_next_line(0);
	while (cmd)
	{
		if (!(checkcmd(cmd)))
		{
			ft_lstclear(&result, free);
			return (0);
		}
		temp = ft_lstnew(cmd);
		if (!temp)
		{
			ft_lstclear(&result, free);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		cmd = get_next_line(0);
	}
	*errorcheck = 0;
	return (result);
}

void	resultout(t_stack *abstack)
{
	if (abstack->btop)
		ft_printf("KO\n");
	else if (endcheck(abstack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	commanddo(t_stack *abstack, t_list *comlst)
{
	t_list	*temp;
	int		last;

	temp = comlst;
	while (temp)
	{
		last = ((char *)(temp->content))[1];
		if (ft_strlen((char *)(temp->content)) == 4)
			last = ((char *)(temp->content))[2];
		if (last != 'a' && last != 'b')
			last = 'a' + 'b';
		if (ft_strlen((char *)(temp->content)) == 4)
			ps_revrotate(abstack, last);
		else
		{
			if (((char *)(temp->content))[0] == 'p')
				ps_push(abstack, last);
			else if (((char *)(temp->content))[0] == 's')
				ps_swap(abstack, last);
			else
				ps_rotate(abstack, last);
		}
		temp = temp->next;
	}
	resultout(abstack);
}
