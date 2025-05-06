/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:38:49 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/06 14:12:54 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>
#include <stdlib.h>

bool	ft_memmatch(char *a, char *b, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && a[i] != 0 && b[i] != 0)
	{
		if (a[i] == b[i])
		{
			i++;
			continue ;
		}
		else
			return (false);
	}
	return (true);
}

t_env	*get_environment_variable(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strmatch(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*get_environment_variable_value(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strmatch(env->key, key))
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}
