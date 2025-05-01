/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:35:13 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/23 17:24:14 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "parser_types.h"
#include "quote_cleanup.h"
#include "tokenizer_helper.h"
#include "utils1.h"
#include <stdio.h>
#include <stdlib.h>

static t_token	*create_token(void *substr, int len)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	if (substr == NULL || *((char *)substr) == 0)
		return (token);
	token->str = ft_calloc(len + 1, sizeof(char));
	if (token->str == NULL)
	{
		free(token);
		return (NULL);
	}
	ft_memcpy(token->str, substr, len);
	token->type = determine_token_type(token->str);
	return (token);
}

static int	find_matching_pair(t_tokenizer *t, int offset)
{
	char	c;
	int		i;
	char	original_c;

	i = 1;
	original_c = t->text[t->cursor + offset];
	c = t->text[t->cursor + offset + i];
	while (c != 0 && c != original_c)
	{
		i++;
		c = t->text[t->cursor + offset + i];
	}
	if (c == original_c)
		return (i);
	else
		return (0);
}

static t_token	*get_next_token(t_tokenizer *t)
{
	char	*substr;
	int		word_len;
	t_token	*token;
	int		pair;

	skip_whitespace(t);
	substr = &(t->text[t->cursor]);
	word_len = 0;
	while (t->text[t->cursor + word_len] != 0 && !ft_isspace(t->text[t->cursor
			+ word_len]))
	{
		if ((t->text[t->cursor + word_len] == '\'' || t->text[t->cursor
				+ word_len] == '\"'))
		{
			pair = find_matching_pair(t, word_len);
			word_len += pair;
		}
		word_len++;
	}
	t->cursor += word_len;
	token = create_token(substr, word_len);
	return (token);
}

void	test_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	// printf("\nTOKENIZER:\n\n");
	while (tokens != NULL)
	{
		// printf("token %d: %s\n", i, tokens->str);
		tokens = tokens->next;
		i++;
	}
}

// NOTE: How should I handle unknown tokens?
t_token	*tokenize(t_tokenizer *tokenizer, t_env *environment, int exit_status)
{
	t_token	*first_token;
	t_token	*token;

	token = get_next_token(tokenizer);
	first_token = token;
	if (token == NULL)
	{
		free_tokens_tokenizer_and_exit(tokenizer, first_token);
	}
	// printf("%d: %s\n", token->type, token->str);
	if (token->type == TOKEN_WORD)
	{
		clean_up_quotes_and_substitute_vars(token, environment, exit_status);
		// printf("(clean) %d: %s\n", token->type, token->str);
	}
	while (token->type != TOKEN_END)
	{
		token->next = get_next_token(tokenizer);
		token = token->next;
		if (token == NULL)
		{
			free_tokens_tokenizer_and_exit(tokenizer, first_token);
		}
		// printf("%d: %s\n", token->type, token->str);
		if (token->type == TOKEN_WORD)
		{
			clean_up_quotes_and_substitute_vars(token, environment,
				exit_status);
			// printf("(clean) %d: %s\n", token->type, token->str);
		}
	}
	test_tokens(first_token);
	tokenizer->text = NULL;
	tokenizer->cursor = 0;
	return (first_token);
}
