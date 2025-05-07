/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_expansion_helper.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:30:46 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/06 13:58:08 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_AND_EXPANSION_HELPER_H
# define QUOTES_AND_EXPANSION_HELPER_H

# include "minishell.h"
# include "parser_types.h"

void			remove_quote_pair(char *str, int idx_a, int idx_b);
int				find_matching_pair_on_str(char *str, int index_a);
int				get_key_len(char *str, int key_index);
char			*get_key_value(char *key, t_env *environment, int exit_status);
t_string_data	expand_variable(t_string_data s, t_env *environment,
					int exit_status);

#endif
