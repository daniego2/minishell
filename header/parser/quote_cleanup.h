/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_cleanup.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:30:46 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/23 17:21:34 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_CLEANUP_H
# define QUOTE_CLEANUP_H

# include "minishell.h"
# include "parser_types.h"
int		find_matching_pair_on_str(char *str);
t_token	*clean_up_quotes_and_substitute_vars(t_token *token, t_env *environment,
			int exit_status);
char	*expand_heredoc_str(char *str, t_env *environment, int exit_status);

#endif
