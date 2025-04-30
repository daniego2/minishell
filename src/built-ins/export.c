#include "minishell.h"

void print_sorted_env(t_env *env)
{
    t_env *copy;
    t_env *current;

    copy = copy_env(env);
    if (!copy)
        return;

    sort_env(&copy);
    current = copy;

    while (current)
    {
        if (current->value && ft_strlen(current->value) > 0)
            printf("declare -x %s=\"%s\"\n", current->key, current->value);
        else
            printf("declare -x %s\n", current->key);
        current = current->next;
    }
    free_env(copy);
}

char *get_key(char *command)
{
    int i;
    char *key;

    i = 0;
    while (command[i] && command[i] != '=')
        i++;

    key = malloc(i + 1);
    i = 0;
    while (command[i] && command[i] != '=')
    {
        key[i] = command[i];
        i++;
    }
    key[i] = '\0';
    return key;
}

char *get_value(char *command)
{
    int i;
    int j;
    char *value;

    i = 0;
    while (command[i] && command[i] != '=')
        i++;

    if (!command[i])
        return NULL;

    value = malloc(ft_strlen(command) - i + 1);
    i++;
    j = 0;
    while (command[i])
    {
        value[j] = command[i];
        i++;
        j++;
    }
    value[j] = '\0';
    return value;
}

int exec_export(t_env **env, char **command)
{
    char *key;
    char *value;

    if (!command[1])
    {
        print_sorted_env(*env);
        return 0;
    }

    key = get_key(command[1]);
    value = get_value(command[1]);

    if (!value)
    {
        value = malloc(1);
        value[0] = '\0';
    }

    if (!update_existing_env(*env, key, value))
        add_node(env, key, value);

    free(key);
    if (value)
        free(value);
    return 0;
}