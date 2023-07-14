/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:03:30 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/13 16:55:49 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lstoverlap(t_list *past, char *player)
{
	t_list	*temp;

	temp = past;
	while (temp)
	{
		if (player == (char *)(temp->content))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	nothing(void *content)
{
	content = 0;
}

int	pathdfs(t_map *map, char *player, char *goal, t_list **past)
{
	t_list	*temp;

	if (player == goal)
		return (1);
	if (ft_strchr("1EX", *player))
		return (0);
	if (ft_lstoverlap(*past, player))
		return (0);
	ft_lstadd_front(past, ft_lstnew((void *)player));
	if (pathdfs(map, player - map->garo, goal, past) == 1)
		return (1);
	if (pathdfs(map, player + map->garo, goal, past) == 1)
		return (1);
	if (pathdfs(map, player - 1, goal, past) == 1)
		return (1);
	if (pathdfs(map, player + 1, goal, past) == 1)
		return (1);
	temp = *past;
	*past = (*past)->next;
	free(temp);
	return (0);
}

void	pathcheck(t_map *map)
{
	char	*player;
	char	*goal;
	char	*temp;
	int		success;
	t_list	*past;

	past = 0;
	map->collection = 0;
	player = ft_strchr(map->plan, 'P');
	goal = ft_strchr(map->plan, 'C');
	while (goal)
	{
		(map->collection)++;
		success = pathdfs(map, player, goal, &past);
		ft_lstclear(&past, &nothing);
		if (!success)
			errorend(map, "Error\n: Wrong Map\n");
		temp = goal + 1;
		goal = ft_strchr(temp, 'C');
	}
	goal = ft_strchr(map->plan, 'E');
	success = pathdfs(map, player, goal, &past);
	ft_lstclear(&past, &nothing);
	if (!success)
		errorend(map, "Error\n: Wrong Map\n");
}
