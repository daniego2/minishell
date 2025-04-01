/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:20:24 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/01 13:33:34 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "parser_types.h"

void	free_tokens_and_exit(t_token *tokens);
void	free_tokens_tokenizer_and_exit(t_tokenizer *tokenizer, t_token *tokens);
void	free_pipeline_and_exit(t_cmd *command_node);

#endif
