/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:54:47 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/12 14:25:14 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	abstack;
	t_list	*comlst;
	int		errorcheck;

	errorcheck = 1;
	if (argc == 1)
		return (-1);
	initialset(&abstack, argv, argc);
	comlst = commandset(&errorcheck);
	if (!errorcheck)
		commanddo(&abstack, comlst);
	else
	{
		write(2, "Error\n", 6);
		allstackfree(&abstack);
		return (-1);
	}
	ft_lstclear(&comlst, free);
	allstackfree(&abstack);
	return (0);
}
