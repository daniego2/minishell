#include "minishell.h"


t_env *get_env(char **env)
{
    int i = 1;
    char **line;
	t_env *environment;

	line = ft_split(env[0], '=');
	environment = create_node(line[0], line[1]);
    while (env[i] != NULL)
    {
		
		line = ft_split(env[i], '=');
        if (line)
		add_node(&environment, line[0], line[1]);
        i++;
    }
	return (environment);
}