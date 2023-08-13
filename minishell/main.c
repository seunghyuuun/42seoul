#include <stdio.h>
#include "env.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*test;
	t_env	*temp;

	if (argc != 1)
		return (-1);
	argv = 0;
	test = envlist(envp);
	temp = test;
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
	return (0);
}
