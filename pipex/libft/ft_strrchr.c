/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:33:23 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/16 13:41:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	tofind;
	char	*temp;
	char	*result;

	tofind = (char)c;
	temp = (char *)s;
	result = 0;
	while (*temp)
	{
		if (*temp == tofind)
			result = temp;
		temp++;
	}
	if (!tofind)
		return (temp);
	return (result);
}
