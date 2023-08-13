#ifndef ENV_H
# define ENV_H

# include <stdlib.h>

typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env	*next;
}	t_env;

t_env	*envlist(char **envp);
void	envadd(t_env **envlst, char *nv);
int	envedit(t_env *envlst, char *nv);

void	envseparate(char *nv, char **name, char **value);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

char	*envsearch(t_env *envlst, char *name);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
