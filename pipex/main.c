/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:11:19 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/19 17:22:32 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_piparg	arg;

	if (argc < 5)
	{
		ft_printf("more argv\n");
		return (-1);
	}
	arg.cmd = cmdmkr(argc, argv);
	if (!arg.cmd)
	{
		ft_printf("alloc fail\n");
		return (-1);
	}
	arg.cmdpath = pathmkr(arg.cmd, envp);
	if (!arg.cmdpath)
	{
		ft_printf("alloc fail\n");
		return (-1);
	}
	arg.inout[0] = open(argv[1], O_RDWR);
	arg.inout[1] = open(argv[argc - 1], O_RDWR);
	piping(&arg, envp, argc - 3);
	threedfree(arg.cmd);
	twodfree(arg.cmdpath);
	return (0);
}
