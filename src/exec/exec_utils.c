/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego <daniego@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:27 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/30 19:21:42 by daniego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_finder(char *target, char **path_batch)
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
	return (path_cpy);
}

char	**get_path(char **env, char *path)
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

char	*find_env_path(char **env_cpy)
{
	int	i;
	
	i = 0;
	while (env_cpy[i])
	{
		if (ft_strncmp(env_cpy[i], "PATH=", 5) == 0)
			return (env_cpy[i] + 5);
		i++;
	}
	return (NULL);
}

char	*process_path_directories(char *command, char *env_path)
{
	char	**path_batch;
	char	*path;
	
	if (!env_path)
		return (NULL);
	path_batch = ft_split(env_path, ':');
	path = path_finder(command, path_batch);
	ft_free_array(path_batch);
	return (path);
}

char	*get_path_to_program(t_cmd *cmd, t_env **env)
{
	char	*path;
	char	*env_path;
	char	**env_cpy;

	if (is_path_to_program(cmd->command[0]))
		return (cmd->command[0]);
	env_cpy = assemble_env(*env);
	env_path = find_env_path(env_cpy);
	path = process_path_directories(cmd->command[0], env_path);
	ft_free_array(env_cpy);
	return (path);
}

void	ft_error(t_cmd *cmd, char *message)
{
	ft_putstr_fd(message, 1);
	free(cmd);
	exit(2);
}


