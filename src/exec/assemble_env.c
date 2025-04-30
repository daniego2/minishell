/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego <daniego@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:04:01 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/30 19:22:37 by daniego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **assemble_env(t_env *env)
{
	int i;
	char **new_env;
	char *aux;

	new_env = malloc(sizeof(char *) * (envsize(env) + 1));
	i = 0;
	while (env != NULL)
	{
		aux = ft_strjoin(env->key, "=");
		new_env[i] = ft_strjoin(aux, env->value);
		i++;
		env = env->next;
		free(aux);
	}
	new_env[i] = NULL;
	return (new_env);
}