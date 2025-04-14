/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/10 17:58:45 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_path_to_program(char *command)
{
	int	i;
	
	i = 0;
	while (command[i])
	{
		if (command[0] == '/' || command[0] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	create_fork(t_cmd *cmd, char *path, t_env **env, int *standard_input, int exit_status)
{

  	int	pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	if (pid == -1)
		ft_error(cmd, "Error: Fork failed");
	if (pid == 0)
	{
		if (cmd->out_fd != -1)
			dup2(cmd->out_fd, STDOUT_FILENO);
		else if (cmd->next != NULL)
			dup2(fd[1], STDOUT_FILENO);
		if (cmd->in_fd != -1)
			dup2(cmd->in_fd, STDIN_FILENO);
		else if (*standard_input != STDIN_FILENO)
			dup2(*standard_input, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (is_builtin(cmd->command[0]))
		{
			exit_status = exec_builtin(cmd, env, exit_status);
			exit(0);
		}
		else
		{
			execve(path, cmd->command, assemble_env(*env));
		}
	}
	close(fd[1]);
	if (*standard_input != STDIN_FILENO)
		close(*standard_input);
	waitpid(pid, &exit_status, 0);
	*standard_input = fd[0];
	return (exit_status);
}

int	check_path(t_cmd *cmd, char **env)
{
	if (!env || !*env)
		ft_error(cmd, "Error: Path not found");
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (0);
		env++;
	}
	ft_error(cmd, "Error: Path not found");
	return (1);
}

int	exec(t_env **env, t_cmd *cmd, int exit_status)
{
	char	*path;
	int		standard_input;

	standard_input = STDIN_FILENO;
	if (!exit_status)
		exit_status = 0;

	while (cmd != NULL)
	{
		cmd->in_fd = get_in_fd(cmd);
		cmd->out_fd = get_out_fd(cmd);
		path = get_path_to_program(cmd, env);

		if (!path && !is_builtin(cmd->command[0]))
		{
			printf("%s: Command not found\n", cmd->command[0]);
			return (127);
		}

		if (is_builtin_pipeless(cmd->command[0]))
			exit_status = exec_builtin(cmd, env, exit_status);
		else
			exit_status = create_fork(cmd, path, env, &standard_input, exit_status);
		unlink(".here_doc");
		cmd = cmd->next;
	}
	if (standard_input != STDIN_FILENO)
		close(standard_input);
	return (exit_status);
}
