#include "minishell.h"

int exec_cd(char **argv)
{
	if (!argv[1])
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("No Home directory");
			return (1);
		}
	}
	else 
	{
		if (chdir(argv[1]) != 0)
		{
			perror("cd");
			return (1);
		}
	}
	return (0);
}