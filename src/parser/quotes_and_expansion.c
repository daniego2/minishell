/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_expansion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:49:54 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/06 13:59:32 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes_and_expansion_helper.h"

static t_string_data	handle_double_quotes(t_string_data s,
		t_env *environment, int exit_status)
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
		s.cursor += 1;
	return (s);
}

static t_string_data	handle_single_quotes(t_string_data s,
		t_env *environment)
{
	s.quote_a = s.cursor;
	s.quote_b = find_matching_pair_on_str(s.str, s.quote_a);
	if (s.quote_b != -1)
	{
		remove_quote_pair(s.str, s.quote_a, s.quote_b);
		s.cursor = s.quote_b - 1;
	}
	else
		s.cursor += 1;
	return (s);
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
			s = expand_variable(s, environment, exit_status);
		else if (s.str[s.cursor] == '\"')
			s = handle_double_quotes(s, environment, exit_status);
		else if (s.str[s.cursor] == '\'')
			s = handle_single_quotes(s, environment);
		else
			s.cursor++;
	}
	token->str = s.str;
	return (token);
}

t_token	*clean_up_quotes(t_token *token, t_env *environment, int exit_status)
{
	t_string_data	s;

	s = (t_string_data){0};
	s.str = token->str;
	while (s.str[s.cursor] != 0)
	{
		if (s.str[s.cursor] == '\"' || s.str[s.cursor] == '\'')
		{
			s.quote_a = s.cursor;
			s.quote_b = find_matching_pair_on_str(s.str, s.quote_a);
			if (s.quote_b != -1)
			{
				token->is_quoted = true;
				remove_quote_pair(s.str, s.quote_a, s.quote_b);
				s.cursor = s.quote_b - 1;
			}
			else
				s.cursor += 1;
		}
		else
			s.cursor++;
	}
	token->str = s.str;
	return (token);
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
