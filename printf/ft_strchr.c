/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:28:22 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/07 20:28:33 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	tofind;
	char	*temp;

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
