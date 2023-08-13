#include "env.h"

// 할당 실패 시 에러처리 추가 필요
 
void	envseparate(char *nv, char **name, char **value)
{
	char	*str;
	char	*temp;

	str = ft_strdup(nv);
	temp = ft_strchr(str, '=');
	*temp = '\0';
	*value = temp + 1;
	temp = str;
	*name = ft_strdup(temp);
	temp = *value;
	*value = ft_strdup(temp);
	free(str);
	// 이후 '' 혹은 "" 처리
}

t_env	*envsearch(t_env *envlst, char *name)
{
	t_env	*temp;
	size_t	namelen;

	temp = envlst;
	namelen = ft_strlen(name);
	while (temp && ft_strncmp(temp->name, name, namelen))
		temp = temp->next;
	return (temp);
}
