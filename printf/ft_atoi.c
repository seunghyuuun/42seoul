/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:29:03 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/07 20:29:06 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skindex(const char *str, long *minus)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(*minus) = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	minus;
	long	result;
	long	temp;

	minus = 1;
	result = 0;
	i = skindex(str, &minus);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = result;
		result = 10 * result + (str[i] - '0');
		if (minus == 1 && temp > result)
			return (-1);
		else if (minus == -1 && temp * minus < result * minus)
			return (0);
		i++;
	}
	return ((int)(minus * result));
}
