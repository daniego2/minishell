/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:05:47 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/01 13:33:34 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdlib.h>

void	free_tokens(t_token *token)
{
	if (token == NULL)
		return ;
	else
	{
		free_tokens(token->next);
		free(token->str);
		free(token);
	}
}

void	free_redirs(t_redir *redir)
{
	if (redir == NULL)
		return ;
	else
	{
		free_redirs(redir->next);
		free(redir);
	}
}

void	free_pipeline(t_cmd *command_node)
{
	if (command_node == NULL)
		return ;
	else
	{
		free_pipeline(command_node->next);
		if (command_node->command)
			free(command_node->command);
		free_redirs(command_node->redir);
		free(command_node);
	}
}
