#include "minishell.h"

void free_env(t_env *env)
{
    t_env *tmp;
    while (env != NULL)
    {
        tmp = env;
        env = env->next;
        free(tmp->key);
        free(tmp->value);
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

void free_pipex(t_pipex *pipex)
{
	t_pipex *tmp;
	while (pipex != NULL)
	{
		tmp = pipex;
		pipex = pipex->next;
		free(tmp->path);
		ft_free_array(tmp->command);
		free(tmp);
	}
}