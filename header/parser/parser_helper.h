/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:09:26 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/05 17:11:22 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HELPER_H
# define PARSER_HELPER_H

# include "parser_types.h"

int		count_word_tokens_in_sequence(t_token *token);
t_cmd	*append_new_command_node(t_cmd *pipeline);
t_cmd	*create_pipeline(void);

#endif
