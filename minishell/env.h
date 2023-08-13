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
void	envedit(t_env **envlst, char *nv);

void	envseparate(char *nv, char **name, char **value);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

t_env	*envsearch(t_env *envlst, char *name);
int	ft_strcmp(const char *s1, const char *s2);

#endif
