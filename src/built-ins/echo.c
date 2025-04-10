#include "minishell.h"


// Tengo que arreglar el input: 'echo -n -n hola' y 'echo -n-n-n-n-n hola'
int exec_echo(char **argv, int exit_status)
{
	int i;
	int newline;

	i = 1;
	newline = 1;
	if (ft_strncmp(argv[1], "-n", 2) == 0)
	{
		newline = 0;
		i++;
	}
	while (argv[i] && argv[i + 1])
	{
		if (ft_strncmp(argv[i], "$?", 2) == 0)
			printf("%i ", exit_status);
		else
			printf("%s ", argv[i]);
		i++;
	}
	if (ft_strncmp(argv[i], "$?", 2) == 0)
		printf("%i", exit_status);
	else
		printf("%s", argv[i]);
	if (newline)
		printf("\n");
	
	return (0);
}