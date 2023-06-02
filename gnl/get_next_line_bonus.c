/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:43:38 by seunghy2          #+#    #+#             */
/*   Updated: 2023/05/29 19:43:43 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_store	*findstore(t_store **lst, int fd)
{
	t_store	*result;

	result = *lst;
	while (result && result->fd != fd)
		result = result->next;
	if (!result && !(read(fd, 0, 0)))
	{
		result = (t_store *)malloc(sizeof(t_store));
		if (!result)
			return (result);
		result->fd = fd;
		result->store = 0;
		result->next = *lst;
		*lst = result;
	}
	return (result);
}

void	nodefree(t_store **lst, int fd)
{
	t_store	*node;
	t_store	*temp;

	node = findstore(lst, fd);
	temp = *lst;
	if (!node)
		return ;
	allfree(node->store, 0, 0);
	if (temp == node)
	{
		*lst = node->next;
		free (node);
		return ;
	}
	while (temp->next != node)
		temp = temp->next;
	temp->next = node->next;
	free (node);
}

int	onelinetaker(char **result, t_store **storelst, int fd, int ready)
{
	char	*storebaby;
	char	*temp;
	char	*baby;
	t_store	*node;

	baby = 0;
	node = findstore(storelst, fd);
	if (!ready)
		*result = ft_strdup("");
	if (!node || !(node->store))
		return (0);
	storebaby = ft_strchr(node->store, '\n');
	if (storebaby)
	{
		*storebaby = '\0';
		if (*(storebaby + 1))
			baby = ft_strdup(storebaby + 1);
	}
	temp = *result;
	*result = ft_strjoin(temp, node->store);
	allfree(temp, node->store, 0);
	node->store = baby;
	if (!(node->store))
		nodefree(storelst, fd);
	return ((storebaby != 0));
}

void	storejoinbuff(t_store *node, char *buff, int letters)
{
	char	*temp;

	buff[letters] = '\0';
	if (!(node->store))
		node->store = ft_strdup("");
	temp = ft_strjoin(node->store, buff);
	allfree(node->store, 0, 0);
	node->store = temp;
}

char	*get_next_line(int fd)
{
	static t_store	*storelst;
	char			*result;
	char			*buff;
	int				letters;

	if (onelinetaker(&result, &storelst, fd, 0) && !(read(fd, 0, 0)))
		return (allfree(result, 0, ft_strjoin(result, "\n")));
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff || !(findstore(&storelst, fd)))
		return (allfree(result, buff, 0));
	letters = read(fd, buff, BUFFER_SIZE);
	if (letters <= 0)
		nodefree(&storelst, fd);
	while (letters)
	{
		if (letters < 0)
			return (allfree(result, buff, 0));
		storejoinbuff(findstore(&storelst, fd), buff, letters);
		if (onelinetaker(&result, &storelst, fd, 1))
			return (allfree(buff, result, ft_strjoin(result, "\n")));
		letters = read(fd, buff, BUFFER_SIZE);
	}
	if (!(ft_strlen(result)))
		return (allfree(buff, result, 0));
	return (allfree(buff, 0, result));
}
