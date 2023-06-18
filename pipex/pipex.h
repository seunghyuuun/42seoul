#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	***cmdmkr(int argc, char **argv);
char	**pathmkr(char ***cmd, char **envp);
void piping(char ***cmd, char **cmdpath, char **envp, int inout[2], int i);

void	threedfree(char ***s);
void	twodfree(char **s);

int	ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

#endif
