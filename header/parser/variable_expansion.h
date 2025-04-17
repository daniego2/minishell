/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:52:13 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/17 15:53:08 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_EXPANSION_H
# define VARIABLE_EXPANSION_H

# include "minishell.h"
# include "parser_types.h"
t_cmd	*expand_variables(t_cmd *pipeline, t_env *env);

#endif
