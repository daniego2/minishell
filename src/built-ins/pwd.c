#include "minishell.h"

int exec_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		printf("Error: getcwd failed\n");
		exit(1);
	}
	else 
	{
		path = getcwd(NULL, 0);
		printf("%s\n", path);
	}	
	free(path);
	return (0);
}