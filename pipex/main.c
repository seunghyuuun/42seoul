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
		manualerror("more argv\n");
	arg.inout[0] = open(argv[1], O_RDONLY);
	arg.inout[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	arg.cmd = cmdmkr(argc, argv);
	arg.cmdpath = pathmkr(&arg, envp);
	piping(&arg, envp, argc - 3);
	threedfree(arg.cmd);
	twodfree(arg.cmdpath);
	return (0);
}
