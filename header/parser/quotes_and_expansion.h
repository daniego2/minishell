/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_and_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:30:46 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/06 13:57:47 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_AND_EXPANSION_H
# define QUOTES_AND_EXPANSION_H

# include "minishell.h"
# include "parser_types.h"

t_token	*clean_up_quotes_and_substitute_vars(t_token *token, t_env *environment,
			int exit_status);
t_token	*clean_up_quotes(t_token *token, t_env *environment, int exit_status);
char	*expand_heredoc_str(char *str, t_env *environment, int exit_status);

#endif
