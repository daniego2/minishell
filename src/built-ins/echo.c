#include "minishell.h"

int exec_echo(char **argv, int exit_status)
{
	int i = 1;
	int newline = 1;

	while (argv[i] && ft_strcmp(argv[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}

	while (argv[i])
	{
		if (ft_strcmp(argv[i], "$?") == 0)
			printf("%i", exit_status);
		else
			printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}

	if (newline)
		printf("\n");

	return (0);
}