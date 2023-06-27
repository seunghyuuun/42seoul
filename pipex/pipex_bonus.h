/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:16:26 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/27 18:00:21 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 42

typedef struct s_piparg
{
	char	***cmd;
	char	**cmdpath;
	int		inout[2];
	int		heredocflag;
}	t_piparg;

void	heremain(int argc, char **argv, char **envp);
char	***bs_cmdmkr(int argc, char **argv, int skip);
char	**pathmkr(t_piparg *arg, char **envp);
void	piping(t_piparg *arg, char **envp, int size);

void	manualerror(char *str);
void	erasearg(t_piparg *arg, char *str);
void	threedfree(char ***s);
void	twodfree(char **s);
int		ft_strcmp(const char *s1, const char *s2);
int		makeorclose(char *endline, int fd);
char	*get_next_line(int fd);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
