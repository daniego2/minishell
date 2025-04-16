/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:08:00 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/16 16:34:02 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envsize(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		i++;
		env = env->next;
	}
	return (i);
}

t_env *create_node(char *key, char *value)
{
	t_env *new_node;
	
    new_node = malloc(sizeof(t_env));
    if (!new_node)
        return NULL;
    new_node->key = ft_strdup(key);
    new_node->value = ft_strdup(value);
    new_node->next = NULL;
    return new_node;
}

void add_node(t_env **head, char *key, char *value)
{
	t_env *aux;

	if (head == NULL)
	{
		create_node(key, value);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = create_node(key, value);

}