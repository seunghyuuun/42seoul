/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:34:09 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 14:34:22 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	abstack;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	initialset(&abstack, argv, argc);
	restbig(&abstack, stacksize(abstack.atop));
	return (0);
}
