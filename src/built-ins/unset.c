#include "minishell.h"

int exec_unset(t_env **env, char **command)
{
	t_env *current_node;
	t_env *prev_node;

	current_node = *env;
	prev_node = NULL;
	while (current_node != NULL)
	{
		if (ft_strcmp(current_node->key, command[1]) == 0)
		{
			prev_node->next = current_node->next;
			if (current_node->value)
				free(current_node->value);
			free(current_node->key);
			free(current_node);
			return (0);
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
	return (0);
}