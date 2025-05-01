#include "minishell.h"

int update_existing_env(t_env *env, char *key, char *value)
{
    while (env)
    {
        if (ft_strcmp(env->key, key) == 0)
        {
            free(env->value);
            env->value = ft_strdup(value);
            return 1;
        }
        env = env->next;
    }
    return 0;
}

void swap_env(t_env *a, t_env *b)
{
    char *temp_key;
    char *temp_value;

    temp_key = a->key;
    temp_value = a->value;

    a->key = b->key;
    a->value = b->value;

    b->key = temp_key;
    b->value = temp_value;
}

void sort_env(t_env **env)
{
    t_env *current;
    t_env *next;

    current = *env;
    while (current)
    {
        next = current->next;
        while (next)
        {
            if (ft_strcmp(current->key, next->key) > 0)
                swap_env(current, next);
            next = next->next;
        }
        current = current->next;
    }
}

t_env *copy_env(t_env *env)
{
    t_env *new_env;
    char *key_copy;
    char *value_copy;

    new_env = NULL;
    while (env)
    {
        key_copy = ft_strdup(env->key);
        value_copy = ft_strdup(env->value);
        add_node(&new_env, key_copy, value_copy);
        free(key_copy);
        if (value_copy)
            free(value_copy);
        env = env->next;
    }
    return new_env;
}