#include "minishell.h"

int is_valid_flag(char *argv)
{
	int j;

	j = 1;
	while (argv[j])
	{
		if (argv[j] != 'n')
		{
			return(false);
		}
		j++;
	}
	return(true);
}

int exec_echo(char **argv, int exit_status)
{
	int i;
	int newline;

	i = 1;
	newline = 1;
	while (ft_strncmp(argv[i], "-n", 2) == 0)
	{
		if (is_valid_flag(argv[i]))
			newline = 0;
		else
			break ;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (newline > 0)
		printf("\n");
	return (0);
}
º