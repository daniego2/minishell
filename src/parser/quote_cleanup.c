/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:26:40 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/24 16:29:08 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h" // WARN: DELETE.
#include "libft.h"
#include "minishell.h"
#include "parser_types.h"
#include "utils2.h"
#include "utils_strings.h"
#include "variable_expansion.h"
#include <stdlib.h>

static void	remove_quote_pair(char *str, int idx_a, int idx_b)
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
static int	find_matching_pair_on_str(char *str, int index_a)
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

typedef struct s_string_data
{
	char				*str;
	int					key_len;
	int					value_len;
	int					cursor;
	int					quote_a;
	int					quote_b;
}						t_string_data;

// INDEX PROVIDED MUST BE OF '$'.
static int	get_key_len(char *str, int key_index)
{
	int	i;

	i = key_index + 1;
	while (!ft_isspace(str[i]) && !is_symbol(str[i]) && str[i] != '\0')
		i++;
	i -= (key_index + 1);
	return (i);
}

static t_string_data	expand_variable(t_string_data s, t_env *environment,
		int exit_status)
{
	int		key_len;
	char	*key;
	char	*value;
	char	*new_str;
	char	*new_str_2;

	key_len = get_key_len(s.str, s.cursor);
	key = clone_str_n(&s.str[s.cursor + 1], key_len);
	// NOTE: Better handling?
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
	// printf("KEY: %s\n", key);
	// printf("VALUE: %s\n", value);
	new_str = cat_str_n_m(s.str, s.cursor, value, ft_strlen(value));
	// printf("new_str: %s\n", new_str);
	new_str_2 = cat_str_n_m(new_str, ft_strlen(new_str), &s.str[s.cursor + 1
			+ key_len], ft_strlen(&s.str[s.cursor + 1 + key_len]));
	// printf("new_str_2: %s\n", new_str_2);
	free(s.str);
	s.str = new_str_2;
	s.cursor = ft_strlen(new_str);
	s.key_len = 1 + key_len;
	s.value_len = ft_strlen(value);
	free(key);
	free(new_str);
	return (s);
}

char	*expand_heredoc_str(char *str, t_env *environment, int exit_status)
{
	t_string_data	s;

	s = (t_string_data){0};
	s.str = str;
	while (s.str[s.cursor] != 0)
	{
		if (s.str[s.cursor] == '$')
			s = expand_variable(s, environment, exit_status);
		else
			s.cursor++;
	}
	return (s.str);
}

t_token	*clean_up_quotes_and_substitute_vars(t_token *token, t_env *environment,
		int exit_status)
{
	t_string_data	s;

	s = (t_string_data){0};
	s.str = token->str;
	while (s.str[s.cursor] != 0)
	{
		if (s.str[s.cursor] == '$')
		{
			s = expand_variable(s, environment, exit_status);
		}
		else if (s.str[s.cursor] == '\"')
		{
			s.quote_a = s.cursor;
			s.quote_b = find_matching_pair_on_str(s.str, s.quote_a);
			if (s.quote_b != -1)
			{
				while (s.cursor < s.quote_b)
				{
					if (s.str[s.cursor] == '$')
					{
						s = expand_variable(s, environment, exit_status);
						s.quote_b -= s.key_len;
						s.quote_b += s.value_len;
						// printf("CURSOR: %s\n", &s.str[s.cursor]);
					}
					else
						s.cursor++;
				}
				remove_quote_pair(s.str, s.quote_a, s.quote_b);
				s.cursor = s.quote_b - 1;
				s.key_len = 0;
				s.value_len = 0;
				s.quote_a = 0;
				s.quote_b = 0;
			}
			else
			{
				s.cursor += 1;
			}
		}
		else if (s.str[s.cursor] == '\'')
		{
			s.quote_a = s.cursor;
			s.quote_b = find_matching_pair_on_str(s.str, s.quote_a);
			if (s.quote_b != -1)
			{
				remove_quote_pair(s.str, s.quote_a, s.quote_b);
				s.cursor = s.quote_b - 1;
			}
			else
			{
				s.cursor += 1;
			}
		}
		else
			s.cursor++;
	}
	token->str = s.str;
	return (token);
}
