#include "minishell.h"

void free_env(t_env *env)
{
    t_env *tmp;

    while (env != NULL)
    {
        tmp = env;
        env = env->next;
		if (tmp->key)
		{
			free(tmp->key);
		}
		if (tmp->value)
		{
        	free(tmp->value);
		}
        free(tmp);
    }
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

