/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:42:53 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:21:10 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_HELPER_H
# define TOKENIZER_HELPER_H

# include "parser_types.h"

t_token_type	determine_token_type(char *str);
void			skip_whitespace(t_tokenizer *tokenizer);

#endif
