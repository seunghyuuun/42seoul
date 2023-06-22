/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:11:19 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/22 15:30:53 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_piparg	arg;

	if (argc < 5)
		manualerror(&arg, "more argv\n");
	arg.envp = envp;
	arg.inout[0] = open(argv[1], O_RDWR);
	arg.inout[1] = open(argv[argc - 1], O_RDWR);
	arg.cmd = cmdmkr(argc, argv, &arg);
	arg.cmdpath = pathmkr(&arg, envp);
	arg.pdarr = (pid_t *)malloc(sizeof(pid_t) * (argc - 3));
	if (!arg.pdarr)
		erasearg(&arg, "alloc fail\n");
	piping(&arg, envp, argc - 3);
	threedfree(arg.cmd);
	twodfree(arg.cmdpath);
	return (0);
}
