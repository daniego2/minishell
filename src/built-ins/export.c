#include "minishell.h"


void sort_env(t_env **env)
{
    t_env *current;
    t_env *next;
    char *temp_key;
    char *temp_value;

    current = *env;
    while (current)
    {
        next = current->next;
        while (next)
        {
            if (ft_strcmp(current->key, next->key) > 0)
            {
                temp_key = current->key;
                current->key = next->key;
                next->key = temp_key;
                temp_value = current->value;
                current->value = next->value;
                next->value = temp_value;
            }
            next = next->next;
        }
        current = current->next;
    }
}

t_env *copy_env(t_env *env)
{
    t_env *new_env;
    t_env *current;
    char *key_copy;
    char *value_copy;

	new_env = NULL;
	current = env;

    while (current)
    {
        key_copy = ft_strdup(current->key);
        if (current->value)
            value_copy = ft_strdup(current->value);
        else
            value_copy = NULL;

        add_node(&new_env, key_copy, value_copy);
		free(key_copy);
		if (value_copy)
			free(value_copy);
        current = current->next;
    }
    return new_env;
}

void print_export(t_env *env)
{
    t_env *copy;
    t_env *current;

	copy = copy_env(env);
	if (copy == NULL)
		return;
    sort_env(&copy);

    current = copy;
    while (current != NULL)
    {
        if (current->value != NULL && ft_strlen(current->value) > 0)
            printf("declare -x %s=\"%s\"\n", current->key, current->value);
        else
            printf("declare -x %s\n", current->key);
        current = current->next;
    }
    free_env(copy);
}

char *get_value(char *command)
{
	int i;
	char *value;

	i = 0;
	while (command[i] != '='  && command[i])
		i++;
	if (command[i] == '\0')
	{
		return (NULL);
	}
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
		print_export(*env);
		return (0);
	}
	key = get_key(command[1]);
	value = get_value(command[1]);
	if (value == NULL)
	{
		value = malloc(sizeof(char) * 1);
		value[0] = '\0';
	}
	current = *env;
	while (current != NULL)
	{
 		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			free(key);
			if (value)
				free(value);
			return (0);
		} 
		current = current->next;
	}

	add_node(env, key, value);
	free(key);
	if (value)
		free(value);
	return (0);
}
