/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:14:53 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/04 16:00:49 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	tofind;
	char	*temp;

	if (!s)
		return (0);
	tofind = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == tofind)
			return (temp);
		temp++;
	}
	if (!tofind)
		return (temp);
	return (0);
}
