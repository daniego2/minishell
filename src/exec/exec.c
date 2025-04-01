/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/01 11:05:12 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_dup2(t_token *token, int fd1, int fd2, int mustclose)
{
	if (dup2(fd1, fd2) == -1)
	{
		ft_error(token, "Error: Dup2 failed\n");
	}
	if (mustclose)
		close(fd1);
}

void	create_fork(char **argv, t_token *token, char *path, t_env *env)
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
			safe_dup2(token, token->out_fd, STDOUT_FILENO, 1);
		}
		if (token->in_fd != -1)
		{
			safe_dup2(token, token->in_fd, STDIN_FILENO, 1);
		}
		else if (token->next != NULL)
		{
			safe_dup2(token, fd[1], STDOUT_FILENO, 1);
		}
		execve(path, token->command, assemble_env(env));
	}
	close (fd[1]);
	safe_dup2(token, fd[0], STDIN_FILENO, 0);
}
	


int	check_path(t_token *token, char **env)
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
}

void exec(t_env *env, t_token *token)
{
	char **path_batch;
	char *path;
	int in_fd;
	int	fd[2];

	while (token != NULL)
	{
		token->in_fd = get_in_fd(token);
		token->out_fd = get_out_fd(token);
		if (is_builtin(token->command[0]))
		{
			exec_builtin(token, token->command, env);
		}
		else
		{
			path_batch = get_path(assemble_env(env), token, path);
			path = path_finder(path_batch, token->command[0], token);
			create_fork(token->command, token, path, env);
		}
		if (token->redir && token->redir->type == INN)
		{
			unlink(".here_doc");
		}
		token = token->next;
	}
}
