/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:15:10 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/19 16:30:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_piparg
{
	char	***cmd;
	char	**cmdpath;
	int		inout[2];
}	t_piparg;

char	***cmdmkr(int argc, char **argv);
char	**pathmkr(char ***cmd, char **envp);
void	piping(t_piparg *arg, char **envp, int size);

void	threedfree(char ***s);
void	twodfree(char **s);

int		ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

#endif
