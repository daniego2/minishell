/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/03 16:40:48 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_dup2(t_cmd *token, int fd1, int fd2, int mustclose)
{
	if (dup2(fd1, fd2) == -1)
	{
		ft_error(token, "Error: Dup2 failed\n");
	}
	if (mustclose)
		close(fd1);
}

void	create_fork(t_cmd *token, char *path, t_env *env, int *standard_input)
{
    int	pid;
	int fd[2];
	
	pipe(fd);
	pid = fork();
	if (pid == -1)
		ft_error(token, "Error: Fork failed");
	if (pid == 0)
	{
		if (token->out_fd != -1)
		{
			dup2(token->out_fd, STDOUT_FILENO);
		}
		else if (token->next != NULL)
		{
			dup2(fd[1], STDOUT_FILENO);
		}
		if (token->in_fd != -1)
		{
			dup2(token->in_fd, STDIN_FILENO);
		}
		else if (*standard_input != STDIN_FILENO)
		{
			dup2(*standard_input, STDIN_FILENO);
		}
		close(fd[0]);
		close(fd[1]);
		if (is_builtin(token->command[0]))
		{
			write (1, "Executing builtin\n", 18);
			exec_builtin(token->command, env);

		}
		else
			execve(path, token->command, assemble_env(env));
	}
	close(fd[1]);
	if (*standard_input != STDIN_FILENO)
		close(*standard_input);
	waitpid(pid, NULL, 0);
	*standard_input = fd[0];
}
	


int	check_path(t_cmd *token, char **env)
{
	if (!env || !*env)
		ft_error(token, "Error: Path not found");
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (0);
		env++;
	}
	ft_error(token, "Error: Path not found");
	return (1);
}

void exec(t_env *env, t_cmd *token)
{
	char **path_batch;
	char *path;
	int standard_input;

	standard_input = STDIN_FILENO;
	while (token != NULL)
	{
		token->in_fd = get_in_fd(token);
		token->out_fd = get_out_fd(token);
		path_batch = get_path(assemble_env(env), path);
		path = path_finder(path_batch, token->command[0], token);
		printf("Path: %s\n", path);
		create_fork(token, path, env, &standard_input);
		printf("Sale del fork\n");
		
		if (token->redir && token->redir->type == REDIR_HEREDOC)
		{
			unlink(".here_doc");
		}
		token = token->next;
	}
	
	if (standard_input != STDIN_FILENO)
	{
        close(standard_input);
	}
}
