/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:07:41 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/05 17:08:56 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_types.h"

t_cmd	*create_pipeline(void)
{
	t_cmd	*command_node;

	command_node = ft_calloc(1, sizeof(t_cmd));
	if (command_node == NULL)
		return (NULL);
	return (command_node);
}

t_cmd	*append_new_command_node(t_cmd *pipeline)
{
	t_cmd	*command_node;

	command_node = pipeline;
	while (command_node->next != NULL)
		command_node = command_node->next;
	command_node->next = ft_calloc(1, sizeof(t_cmd));
	command_node = command_node->next;
	if (command_node == NULL)
	{
		return (NULL);
	}
	return (command_node);
}

int	count_word_tokens_in_sequence(t_token *token)
{
	int	number_of_word_tokens_in_sequence;

	number_of_word_tokens_in_sequence = 0;
	while (token->type == TOKEN_WORD)
	{
		number_of_word_tokens_in_sequence++;
		token = token->next;
	}
	return (number_of_word_tokens_in_sequence);
}
