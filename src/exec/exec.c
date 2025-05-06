/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 18:59:21 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	is_path_to_program(char *command)
{
	int	i;

	i = 0;
	while (command && command[i])
	{
		if (command[0] == '/' || command[0] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	handle_standard_command(t_cmd *cmd, t_env **env, char *path,
		int *standard_input)
{
	int	exit_status;

	exit_status = 0;
	if (path == NULL && cmd->command[0] == NULL && cmd->next == NULL)
	{
		return (127);
	}
	if (is_builtin_pipeless(cmd->command[0]))
		exit_status = exec_builtin(cmd, env, exit_status);
	else
	{
		exit_status = create_fork(cmd, path, env, standard_input);
	}
	return (exit_status);
}

int	process_command(t_cmd *cmd, t_env **env, int *standard_input,
		int exit_status)
{
	char	*path;

	g_signal = 4;
	cmd->in_fd = get_in_fd(cmd, *(env));
	if (cmd->in_fd == 6969)
		return (130);
	if (cmd->redir != NULL && cmd->in_fd == -69)
	{
		printf("minishell: %s: No such file or directory\n",
			cmd->redir->filename);
		return (1);
	}
	cmd->out_fd = get_out_fd(cmd);
	path = get_path_to_program(cmd, env);
	exit_status = handle_standard_command(cmd, env, path, standard_input);
	return (exit_status);
}

int	exec(t_env **env, t_cmd *cmd, int exit_status)
{
	int	standard_input;
	int	result;

	g_signal = 0;
	standard_input = STDIN_FILENO;
	if (!exit_status)
		exit_status = 0;
	while (cmd != NULL)
	{
		result = process_command(cmd, env, &standard_input, exit_status);
		if (cmd->redir != NULL && cmd->in_fd == -69)
		{
			exit_status = result;
			cmd = cmd->next;
			continue ;
		}
		exit_status = result;
		if (WIFEXITED(result))
		{
			exit_status = WEXITSTATUS(result);
		}
		cmd = cmd->next;
	}
	if (standard_input != STDIN_FILENO)
		close(standard_input);
	g_signal = 1;
	return (exit_status);
}
