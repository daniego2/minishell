/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/24 13:46:25 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			if (execve(path, cmd->command, assemble_env(*env)) == -1)
			{
				write(2, cmd->command[0], ft_strlen(cmd->command[0]));
				write(2, ": command not found\n", 20);
				exit(127);
			}
		}
	}
	close(fd[1]);
	if (*standard_input != STDIN_FILENO)
		close(*standard_input);
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		exit_status = 128 + WTERMSIG(exit_status);
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
		if (cmd->redir != NULL && cmd->in_fd == -69)
		{
			cmd = cmd->next;
			continue;
		}
		cmd->out_fd = get_out_fd(cmd);
		path = get_path_to_program(cmd, env);
		if (path == NULL && cmd->command[0] == NULL && cmd->next == NULL)
			return(127);
		if (is_builtin_pipeless(cmd->command[0]))
			exit_status = exec_builtin(cmd, env, exit_status);
		else
			exit_status = create_fork(cmd, path, env, &standard_input, exit_status);
		if (path)
            free(path);	
		cmd = cmd->next;
	}
	if (standard_input != STDIN_FILENO)
		close(standard_input);
	return (exit_status);
}
