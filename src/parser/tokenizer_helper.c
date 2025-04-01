/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:41:05 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:20:37 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include "utils1.h"

void	skip_whitespace(t_tokenizer *tokenizer)
{
	while (ft_isspace(tokenizer->text[tokenizer->cursor]))
		tokenizer->cursor++;
}

t_token_type	determine_token_type(char *str)
{
	if (ft_strmatch(str, ">"))
		return (TOKEN_REDIR_OUT);
	if (ft_strmatch(str, ">>"))
		return (TOKEN_APPEND);
	if (ft_strmatch(str, "<"))
		return (TOKEN_REDIR_IN);
	if (ft_strmatch(str, "<<"))
		return (TOKEN_HEREDOC);
	if (ft_strmatch(str, "|"))
		return (TOKEN_PIPE);
	else
		return (TOKEN_WORD);
}
