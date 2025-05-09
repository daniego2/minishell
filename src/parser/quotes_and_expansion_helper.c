/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_expansion_helper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:26:40 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/08 14:25:52 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "parser_types.h"
#include "utils2.h"
#include "utils_strings.h"
#include "variable_expansion.h"
#include <stdlib.h>

void	remove_quote_pair(char *str, int idx_a, int idx_b)
{
	int	i;

	i = idx_a;
	while (i + 1 < idx_b && str[i + 1] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
	if (str[i + 1] == '\0')
	{
		str[i] = '\0';
		return ;
	}
	while (str[i + 2] != '\0')
	{
		str[i] = str[i + 2];
		i++;
	}
	if (str[i + 2] == '\0')
		str[i] = '\0';
}

// Returns -1 if pair isn't found.
int	find_matching_pair_on_str(char *str, int index_a)
{
	char	c;
	int		i;
	char	original_c;

	original_c = str[index_a];
	i = index_a + 1;
	c = str[i];
	while (c != '\0' && c != original_c)
	{
		i++;
		c = str[i];
	}
	if (c == original_c)
		return (i);
	else
		return (-1);
}

// INDEX PROVIDED MUST BE OF '$'.
int	get_key_len(char *str, int key_index)
{
	int	i;

	i = key_index + 1;
	while (!ft_isspace(str[i]) && !is_symbol(str[i]) && str[i] != '\0')
		i++;
	i -= (key_index + 1);
	return (i);
}

char	*get_key_value(char *key, t_env *environment, int exit_status)
{
	char	*value;

	if (key == NULL)
		exit(1);
	else if (key[0] == '?' && key[1] == '\0')
		value = ft_itoa(exit_status);
	else
	{
		value = get_environment_variable_value(environment, key);
		if (!value)
			value = "";
	}
	return (value);
}

t_string_data	expand_variable(t_string_data s, t_env *environment,
		int exit_status)
{
	int		key_len;
	char	*key;
	char	*value;
	char	*new_str;
	char	*new_str_2;

	key_len = get_key_len(s.str, s.cursor);
	key = clone_str_n(&s.str[s.cursor + 1], key_len);
	value = get_key_value(key, environment, exit_status);
	new_str = cat_str_n_m(s.str, s.cursor, value, ft_strlen(value));
	new_str_2 = cat_str_n_m(new_str, ft_strlen(new_str), &s.str[s.cursor + 1
			+ key_len], ft_strlen(&s.str[s.cursor + 1 + key_len]));
	free(s.str);
	s.str = new_str_2;
	s.cursor = ft_strlen(new_str);
	s.key_len = 1 + key_len;
	s.value_len = ft_strlen(value);
	if (ft_strcmp(key, "?") == 0)
		free(value);
	free(key);
	free(new_str);
	return (s);
}
