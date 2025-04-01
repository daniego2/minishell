/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:27 by daniego2          #+#    #+#             */
/*   Updated: 2025/02/25 15:34:03 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_finder(char **path_batch, char *target, t_token *token)
{
	int		i;
	char	*path_cpy;
	char	*temp;

	temp = NULL;
	path_cpy = NULL;
	i = 0;
	while (path_batch[i] && target && *target)
	{
		temp = ft_strjoin(path_batch[i], "/");
		path_cpy = ft_strjoin(temp, target);
		free(temp);
		if (access(path_cpy, R_OK) == 0)
			break ;
		free(path_cpy);
		path_cpy = NULL;
		i++;
	}
	if (!path_cpy)
		ft_error(token, "Error: No path found");
	return (path_cpy);
}

char	**get_path(char **env, t_token *token, char *path)
{
	int		i;
	char	**path_batch;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = ft_strdup(env[i] + 5);
	path_batch = ft_split(path, ':');
	free(path);
	return (path_batch);
}

void	ft_error(t_token *token, char *message)
{
	//close(token->prev_fd);
	ft_putstr_fd(message, 1);
	free(token);
	exit(2);
}


