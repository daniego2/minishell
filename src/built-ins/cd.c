#include "minishell.h"

int exec_cd(char **argv)
{
	if (!argv[1])
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("No Home directory");
		}
		else 
		{
			printf("A tu casa\n");
			chdir(getenv("HOME"));
		}
	}
	else 
	{
		printf("nos vamo a %s\n", argv[1]);
		chdir(argv[1]);
	}
	return (69);
}