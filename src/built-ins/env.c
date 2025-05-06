/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:24:53 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 19:02:47 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_env(t_env *env)
{
	t_env	*aux;

	aux = env;
	while (aux != NULL)
	{
		if (aux->value == NULL || aux->value[0] == '\0')
		{
			aux = aux->next;
		}
		else
		{
			printf("%s=%s\n", aux->key, aux->value);
			aux = aux->next;
		}
	}
	return (0);
}
