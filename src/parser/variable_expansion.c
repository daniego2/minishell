/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:46:55 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/17 15:50:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils2.h"
#include <stdbool.h>

// Pass key with the preceding "$".
static char	*substitute_variable(char *str, char *key, char *value,
		bool first_substition)
{
	int		prefix_len;
	int		key_len;
	int		value_len;
	char	*new_str;
	int		j;
	int		k;
	int		i;

	prefix_len = 0;
	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	new_str = ft_calloc(ft_strlen(str) - key_len + value_len + 1, sizeof(char));
	if (new_str == NULL)
	{
		// TODO: Handle.
	}
	while (str[prefix_len] != '\0')
	{
		if (ft_substrmatch(&str[prefix_len], key))
		{
			break ;
		}
		prefix_len++;
	}
	i = 0;
	while (i < prefix_len && str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	i = 0;
	while (i < value_len)
	{
		new_str[prefix_len + i] = value[i];
		i++;
	}
	i = prefix_len + value_len;
	j = prefix_len + key_len;
	while (str[j] != '\0')
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	if (!first_substition)
		free(str);
	return (new_str);
}

static bool	is_symbol(char c)
{
	if (c == '!' || c == '.' || c == ',' || c == '?' || c == '$')
		return (true);
	else
		return (false);
}

t_cmd	*expand_variables(t_cmd *pipeline, t_env *env)
{
	t_cmd	*node;
	char	*value;
	int		i;
	int		j;
	int		key_len;
	char	*str;
	char	*key;
	t_env	*var;
	bool	first_substition;

	node = pipeline;
	while (node != NULL)
	{
		i = 0;
		while (node->command[i] != NULL)
		{
			first_substition = true;
			str = node->command[i];
			j = 0;
			while (str[j] != '\0')
			{
				if (str[j] == '$' && str[j + 1] != '\0' && str[j + 1] != '$'
					&& !ft_isspace(str[j + 1]))
				{
					key_len = 1;
					while (str[j + key_len] != '\0' && !ft_isspace(str[j
							+ key_len]) && !is_symbol(str[j + key_len]))
					{
						key_len++;
					}
					key = ft_calloc(1 + key_len + 1, sizeof(char));
					ft_memcpy(key, &str[j], key_len);
					var = get_environment_variable(env, &key[1]);
					if (var == NULL)
						value = "";
					else
						value = var->value;
					str = substitute_variable(str, key, value,
							first_substition);
					node->command[i] = str;
					first_substition = false;
					free(key);
				}
				j++;
			}
			i++;
		}
		node = node->next;
	}
	return (pipeline);
}
