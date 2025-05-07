/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:40:13 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/23 16:36:58 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

# include "minishell.h"
// int		ft_strlen(char *str);
// char	*ft_strdup(char *str);
t_env	*get_environment_variable(t_env *env, char *key);
char	*get_environment_variable_value(t_env *env, char *key);

#endif
