/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:25:22 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/01 13:33:34 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRS_H
# define REDIRS_H

# include "parser_types.h"

t_error	parse_redirections(t_cmd *command_node, t_token **token);

#endif
