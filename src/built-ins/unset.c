/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:25:13 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/07 21:39:05 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_node(t_env **env, char *key)
{
	t_env	*current_node;
	t_env	*prev_node;

	current_node = *env;
	prev_node = NULL;
	while (current_node != NULL)
	{
		if (ft_strcmp(current_node->key, key) == 0)
		{
			if (prev_node)
				prev_node->next = current_node->next;
			else
				*env = current_node->next;
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

int	exec_unset(t_env **env, char **command)
{
	int	i;
	int	exit_status;

	if (!command[1])
		return (0);
	exit_status = 0;
	i = 1;
	while (command[i])
	{
		unset_node(env, command[i]);
		i++;
	}
	return (exit_status);
}
