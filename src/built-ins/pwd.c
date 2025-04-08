#include "minishell.h"

int exec_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		// poner el exit status a 1
		printf("Error: getcwd failed\n");
		exit(1);
	}
	else 
	{
		// poner el exit status a 0
		path = getcwd(NULL, 0);
		printf("%s\n", path);
	}	
	free(path);
	return (69);
}