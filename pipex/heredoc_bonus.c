/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:54:04 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/27 18:00:56 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heremain(int argc, char **argv, char **envp)
{
	t_piparg	arg;

	if (argc < 6)
		manualerror("pipex: more argv\n");
	arg.heredocflag = 1;
	arg.inout[0] = makeorclose(argv[2], 0);
	arg.inout[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	arg.cmd = bs_cmdmkr(argc, argv, 3);
	arg.cmdpath = pathmkr(&arg, envp);
	if (arg.inout[0] != -1)
		piping(&arg, envp, argc - 4);
	threedfree(arg.cmd);
	twodfree(arg.cmdpath);
	exit (0);
}
