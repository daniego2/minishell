/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:15:40 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:53:47 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "parser_types.h"
#include "stdio.h"
#include "utils1.h"
#include <assert.h> // WARN: Delete.

static t_redir	*append_new_redir(t_command_node *command_node)
{
	t_redir	*new_redir;
	t_redir	*redir_cursor;

	new_redir = ft_calloc(1, sizeof(t_redir));
	if (new_redir == NULL)
		return (NULL);
	if (command_node->redir == NULL)
		command_node->redir = new_redir;
	else
	{
		redir_cursor = command_node->redir;
		while (redir_cursor->next_redir != NULL)
			redir_cursor = redir_cursor->next_redir;
		redir_cursor->next_redir = new_redir;
	}
	return (new_redir);
}

static void	set_redir_type(t_redir *redir, t_token *token)
{
	if (token->type == TOKEN_REDIR_OUT)
		redir->type = REDIR_OUT;
	else if (token->type == TOKEN_REDIR_IN)
		redir->type = REDIR_IN;
	else if (token->type == TOKEN_APPEND)
		redir->type = REDIR_APPEND;
	else if (token->type == TOKEN_HEREDOC)
		redir->type = REDIR_HEREDOC;
	else
		assert(0);
}

static void	set_redir_filename(t_redir *redir, t_token *token)
{
	if (token->type == TOKEN_WORD)
	{
		redir->filename = token->str;
		// NOTE: May be better to copy str.
		// printf("redir->filename: %s\n", redir->filename);
	}
	else
	{
		// TODO: Handle error case.
		printf("NEED TO HANDLE REDIR NO FILENAME ERROR CASE");
		assert(0);
	}
}

t_token	*parse_redirections(t_command_node *command_node, t_token *token)
{
	t_redir	*redir;

	while (token->type == TOKEN_REDIR_OUT || token->type == TOKEN_REDIR_IN
		|| token->type == TOKEN_APPEND || token->type == TOKEN_HEREDOC)
	{
		redir = append_new_redir(command_node);
		if (redir == NULL)
		{
			free_redirs(command_node->redir);
			command_node->redir = NULL;
			return (NULL);
		}
		set_redir_type(redir, token);
		token = token->next;
		// printf("redir->type: %d\n", redir->type);
		set_redir_filename(redir, token);
		token = token->next;
	}
	return (token);
}
