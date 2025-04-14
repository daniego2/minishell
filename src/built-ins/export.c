#include "minishell.h"

char *get_value(char *command)
{
	int i;
	char *value;

	i = 0;
	while (command[i] != '='  && command[i])
		i++;
	value = malloc(sizeof(char) * ft_strlen(command) - i + 1);
	i++;
	int j = 0;
	while (command[i] != '\0' && command[i])
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
	while (command[i] != '=' && command[i])
		i++;
	key = malloc(sizeof(char) * i + 1);
	i = 0;
	while (command[i] != '=' && command[i])
	{
		key[i] = command[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

int exec_export(t_env **env, char **command)
{
	char *key;
	char *value;
	t_env *current;

	if (!command[1])
	{
		printf("No hay command[1]\n");
		return (1);
	}
	key = get_key(command[1]);
	value = get_value(command[1]);
	current = *env;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return (0);
		}
		current = current->next;
	}
	add_node(env, key, value);
	return (0);
}