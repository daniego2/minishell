/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:38:49 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/24 13:26:12 by cargonz2         ###   ########.fr       */
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
		// printf("%s=%s\n", env->key, env->value);
		// printf("key: %s\n", key);
		// printf("OMEGA\n");
		if (ft_strmatch(env->key, key))
		{
			// printf("AHHHHHHHHHHHHHHHH\n");
			// printf("%s=%s\n", env->key, env->value);
			return (env->value);
		}
		env = env->next;
	}
	// // WARN: DELETE
	// printf("%s=\n", env->key);
	return (NULL);
}

/*
char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
*/
