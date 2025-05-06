/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:13:30 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/05 17:16:39 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "libft.h"
#include "minishell.h"
#include "parser_helper.h"
#include "parser_types.h"
#include "redirs.h"
#include "utils1.h"
#include <assert.h>
#include <stdio.h>

// WARN: It's a problem if I free the token's memory. Copy instead if need be.
static t_error	parse_command(t_cmd *command_node, t_token **token)
{
	int	i;
	int	word_token_count;

	word_token_count = count_word_tokens_in_sequence(*token);
	command_node->command = ft_calloc(word_token_count + 1, sizeof(char *));
	if (command_node->command == NULL)
		return (ERROR_BAD_ALLOCATION);
	i = 0;
	while (i < word_token_count)
	{
		command_node->command[i] = (*token)->str;
		*token = (*token)->next;
		i++;
	}
	return (ERROR_NONE);
}

t_cmd	*parse_pipe(t_cmd *command_node, t_cmd *pipeline, t_token **token)
{
	command_node = append_new_command_node(command_node);
	if (command_node == NULL)
		free_pipeline_and_exit(pipeline);
	(*token) = (*token)->next;
	if ((*token)->type == TOKEN_END)
	{
		printf("minishell: expected command, got \"%s\"\n", (*token)->str);
		return (NULL);
	}
	return (command_node);
}

t_cmd	*parse_after_redirs(t_token **token, t_cmd *command_node,
		t_cmd **pipeline)
{
	if ((*token)->type == TOKEN_PIPE)
	{
		command_node = parse_pipe(command_node, *pipeline, token);
		if (command_node == NULL)
			return (NULL);
	}
	else if ((*token)->type != TOKEN_END && (*token)->type != TOKEN_WORD)
	{
		printf("minishell: expected pipe, got \"%s\"\n", (*token)->str);
		return (NULL);
	}
	return (command_node);
}

t_cmd	*parse_tokens(t_token *first_token, t_env *env)
{
	t_cmd	*command_node;
	t_cmd	*pipeline;
	t_token	*token;
	t_error	error;

	token = first_token;
	pipeline = create_pipeline();
	if (pipeline == NULL)
		free_tokens_and_exit(first_token);
	command_node = pipeline;
	while (token->type != TOKEN_END)
	{
		error = parse_command(command_node, &token);
		if (error == ERROR_BAD_ALLOCATION)
			free_pipeline_and_exit(pipeline);
		error = parse_redirections(command_node, &token);
		if (error == ERROR_BAD_ALLOCATION)
			free_pipeline_and_exit(pipeline);
		else if (error == ERROR_BAD_TOKEN)
			return (NULL);
		command_node = parse_after_redirs(&token, command_node, &pipeline);
		if (command_node == NULL)
			return (NULL);
	}
	return (pipeline);
}
