/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:15:12 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/01 13:33:34 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "parser_types.h"
#include "stdlib.h"

void	free_tokens_and_exit(t_token *tokens)
{
	free_tokens(tokens);
	exit(EXIT_FAILURE);
}

void	free_tokens_tokenizer_and_exit(t_tokenizer *tokenizer, t_token *tokens)
{
	free(tokenizer);
	free_tokens(tokens);
	exit(EXIT_FAILURE);
}

void	free_pipeline_and_exit(t_cmd *command_node)
{
	free_pipeline(command_node);
	exit(EXIT_FAILURE);
}
