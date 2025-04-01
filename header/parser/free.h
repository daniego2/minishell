/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:17:41 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:18:02 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "parser_types.h"

void	free_tokens(t_token *token);
void	free_redirs(t_redir *redir);
void	free_pipeline(t_command_node *command_node);

#endif
