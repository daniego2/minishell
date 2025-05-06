/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:25:36 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 19:00:27 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	dup_manager(t_cmd *cmd, t_io io)
{
	if (cmd->out_fd != -1)
		dup2(cmd->out_fd, STDOUT_FILENO);
	else if (cmd->next != NULL)
		dup2(io.fd[1], STDOUT_FILENO);
	if (cmd->in_fd != -1)
		dup2(cmd->in_fd, STDIN_FILENO);
	else if (*(io.standard_input) != STDIN_FILENO)
		dup2(*(io.standard_input), STDIN_FILENO);
	close(io.fd[0]);
	close(io.fd[1]);
}

void	handle_child_process(t_cmd *cmd, char *path, t_env **env, t_io io)
{
	int		exit_status;
	char	**env_array;

	exit_status = 0;
	dup_manager(cmd, io);
	if (is_builtin(cmd->command[0]))
	{
		exit_status = exec_builtin(cmd, env, exit_status);
		exit(0);
	}
	else
	{
		env_array = assemble_env(*env);
		if (!path || execve(path, cmd->command, env_array) == -1)
		{
			if (env_array)
				ft_free_array(env_array);
			write(2, cmd->command[0], ft_strlen(cmd->command[0]));
			write(2, ": command not found\n", 20);
			exit(127);
		}
	}
}

int	handle_parent_process(int pid, int *standard_input, int *fd,
		int exit_status)
{
	close(fd[1]);
	if (*standard_input != STDIN_FILENO)
		close(*standard_input);
	waitpid(pid, &exit_status, 0);
	if (g_signal == SIGINT || g_signal == SIGQUIT)
	{
		exit_status = 128 + g_signal;
	}
	*standard_input = fd[0];
	return (exit_status);
}

int	create_fork(t_cmd *cmd, char *path, t_env **env, int *standard_input)
{
	int		pid;
	int		fd[2];
	int		exit_status;
	t_io	io;

	exit_status = 0;
	pipe(fd);
	io.standard_input = standard_input;
	io.fd[0] = fd[0];
	io.fd[1] = fd[1];
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		handle_child_process(cmd, path, env, io);
	return (handle_parent_process(pid, standard_input, fd, exit_status));
}
