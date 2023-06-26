/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:15:52 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/26 17:36:40 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_piparg	arg;

	if (!(ft_strcmp(argv[1], "here_doc")))
		heremain(argc, argv, envp);
	if (argc < 5)
		manualerror("pipex: more argv\n");
	arg.inout[0] = open(argv[1], O_RDONLY);
	if (arg.inout[0] == -1)
		perror("pipex");
	arg.inout[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	arg.cmd = bs_cmdmkr(argc, argv, 2);
	arg.cmdpath = pathmkr(&arg, envp);
	if (arg.inout[0] != -1)
		piping(&arg, envp, argc - 3);
	threedfree(arg.cmd);
	twodfree(arg.cmdpath);
	return (0);
}
