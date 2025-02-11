#include "minishell.h"


void get_env(char **env, t_env **environment)
{
    int i = 1;
    char **line;

	line = ft_split(env[0], '=');
	*environment = create_node(line[0], line[1]);
    while (env[i] != NULL)
    {

        line = ft_split(env[i], '=');
        if (line)
            add_node(environment, line[0], line[1]);
        i++;
    }
}