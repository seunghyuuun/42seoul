#include "envset.h"

// 할당 실패 시 에러처리 추가 필요

t_env	*envlist(char **envp)
{
	t_env	*result;
	t_env	**temp;
	size_t	i;

	i = 0;
	result = 0;
	temp = &result;
	while (envp[i + 1])
	{
		*temp = (t_env *)malloc(sizeof(t_env));
		envseparate(envp[i], &((*temp)->name), &((*temp)->value));
		(*temp)->next = 0;
		i++;
		temp = &((*temp)->next);
	}
	return (result);
}

int	envedit(t_env *envlst, char *nv)
{
	t_env	*envedit;
	char	*name;
	char	*value;

	envseparate(nv, &name, &value);
	envedit = envsearch(envlst, name);
	free(name);
	if (!envedit)
	{
		free(value);
		return (-1);
	}
	free(envedit->value);
	envedit->value = value;
	return (0);
}

void	envadd(t_env **envlst, char *nv)
{
	t_env	*temp;

	temp = *envlst;
	*envlst = (t_env *)malloc(sizeof(t_env));
	nodeinit(*envlst, nv);
	(*envlst)->next = temp;
}
