/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:54:47 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/04 15:55:25 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	abstack;
	t_list	*comlst;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	initialset(&abstack, argv, argc);
	comlst = commandset();
	if (comlst)
		commanddo(&abstack, comlst);
	else
	{
		ft_printf("Error\n");
		allstackfree(&abstack);
		return (-1);
	}
	ft_lstclear(&comlst, free);
	allstackfree(&abstack);
	return (0);
}
