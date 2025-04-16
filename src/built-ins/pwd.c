#include "minishell.h"

int exec_pwd(void)
{
	char *path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		perror("getcwd failed");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", path);
	free(path);
	return 0;
}