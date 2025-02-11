/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:27 by daniego2          #+#    #+#             */
/*   Updated: 2025/02/05 20:01:31 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipex	*init_struct(void)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->prev_fd = 0;
	pipex->out_fd = 1;
	pipex->path = NULL;
	return (pipex);
}

char	*path_finder(char **path_batch, char *target)
{
	int		i;
	char	*path_cpy;
	char	*temp;

	path_cpy = NULL;
	i = 0;
	while (path_batch[i])
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
		ft_error("Error: No path found");
	return (path_cpy);
}

char	**get_path(char **env, t_pipex *t_pipex)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	t_pipex->path = ft_strdup(env[i] + 5);
	path = ft_split(t_pipex->path, ':');
	free(t_pipex->path);
	return (path);
}

void	ft_error(char *message)
{
	ft_putstr_fd(message, 1);
	exit(2);
}

