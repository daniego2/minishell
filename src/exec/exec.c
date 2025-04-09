/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/07 20:18:16 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_path_to_program(char *command)
{
	int i;

	while (command[i])
	{
		if (command[0] == '/' || command[0] == '.')
			return (1);
		i++;
	}
	return (0);
}




int	create_fork(t_cmd *token, char *path, t_env **env, int *standard_input)
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
			dup2(token->out_fd, STDOUT_FILENO);
		else if (token->next != NULL)
			dup2(fd[1], STDOUT_FILENO);
		if (token->in_fd != -1)
			dup2(token->in_fd, STDIN_FILENO);
		else if (*standard_input != STDIN_FILENO)
			dup2(*standard_input, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (is_builtin(token->command[0]))
		{
			token->exit_status = exec_builtin(token->command, env);
			exit(0);
		}
		else
		{
			execve(path, token->command, assemble_env(*env));
		}
	}
	close(fd[1]);
	if (*standard_input != STDIN_FILENO)
		close(*standard_input);
	waitpid(pid, &token->exit_status, 0);
	if (WIFEXITED(token->exit_status))
        token->exit_status = WEXITSTATUS(token->exit_status);
    // Si el proceso terminó por una señal, ajustamos el exit status
    else if (WIFSIGNALED(token->exit_status))
        token->exit_status = 128 + WTERMSIG(token->exit_status);
    else
        // Si no sabemos cómo terminó el proceso, asignamos un código genérico
        token->exit_status = 1;
	printf("exit status: %d\n", token->exit_status);
	*standard_input = fd[0];
	free(path);
	return (token->exit_status);
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

int exec(t_env **env, t_cmd *token)
{
	char *path;
	int standard_input;
	int aux_status;

	standard_input = STDIN_FILENO;
	while (token != NULL)
	{
		token->in_fd = get_in_fd(token);
		token->out_fd = get_out_fd(token);
		path = get_path_to_program(token, env);
		if (!path && !is_builtin(token->command[0]))
		{
			printf("Error: No hay Path maquinón\n");
			return (token->exit_status);
		}
		if (is_builtin_pipeless(token->command[0]))
			token->exit_status = exec_builtin(token->command, env);
		else
			token->exit_status = create_fork(token, path, env, &standard_input);
		unlink(".here_doc");
		aux_status = token->exit_status;
		token = token->next;
	}
	if (standard_input != STDIN_FILENO)
	{
		close(standard_input);
	}
	return(aux_status);
}
