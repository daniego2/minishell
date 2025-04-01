/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:05:47 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:22:01 by cargonz2         ###   ########.fr       */
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
		free_redirs(redir->next_redir);
		free(redir);
	}
}

void	free_pipeline(t_command_node *command_node)
{
	if (command_node == NULL)
		return ;
	else
	{
		free_pipeline(command_node->next);
		if (command_node->command_str_arr)
			free(command_node->command_str_arr);
		free_redirs(command_node->redir);
		free(command_node);
	}
}
