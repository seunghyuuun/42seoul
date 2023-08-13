#include <stdio.h>
#include "env.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*test;
	t_env	*temp;

	if (argc != 2)
		return (-1);
	test = envlist(envp);
	temp = test;
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
	printf("--------------------------\n");

	envedit(&test, argv[1]);
	temp = test;
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
	return (0);
}
