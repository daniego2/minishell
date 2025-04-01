#include "../minishell.h"

char *get_value(char *command)
{
	int i;
	char *value;

	i = 0;
	while (command[i] != '=')
		i++;
	value = malloc(sizeof(char) * ft_strlen(command) - i + 1);
	i++;
	int j = 0;
	while (command[i] != '\0')
	{
		value[j] = command[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}

char *get_key(char *command)
{
	int i;
	char *key;

	i = 0;
	while (command[i] != '=')
		i++;
	key = malloc(sizeof(char) * i + 1);
	i = 0;
	while (command[i] != '=')
	{
		key[i] = command[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

void exec_export (t_env **env, char **command)
{
	char *key;
	t_env *current;

	current = *env;
	while (current != NULL)
	{
		key = get_key(command[1]);
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
		{
			free(current->value);
			current->value = get_value(command[1]);
			free(key);
			return;
		}
		free(key);
		current = current->next;
	}
	add_node(env, get_key(command[1]), get_value(command[1]));
}