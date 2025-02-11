/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by daniego2          #+#    #+#             */
/*   Updated: 2025/02/05 20:52:02 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_process(t_pipex *t_pipex, int fd[2])
{
	close (fd[0]);
	close (fd[1]);
	execve (t_pipex->path, t_pipex->command, t_pipex->env);
}

void	setup_child(t_pipex *t_pipex, int fd[2])
{
	dup2(t_pipex->prev_fd, STDIN_FILENO); 
	dup2(t_pipex->out_fd, STDOUT_FILENO);
}

void	create_fork(char **argv, t_pipex *t_pipex)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error("Child process failed");
	pid = fork();
	if (pid == 0)
	{
		//setup_child(t_pipex, fd);
		execute_process(t_pipex, fd);
	}
	close(fd[1]);
	t_pipex->prev_fd = fd[0];
	//ft_free_array(t_pipex->command);
	
	//free(t_pipex->path);
}

void do_pipex(char **env, t_pipex *t_pipex)
{
	t_pipex->env = env;
	t_pipex->path_batch = get_path(env, t_pipex);
	while (t_pipex != NULL)
	{
		//t_pipex->path = path_finder(t_pipex->path_batch, t_pipex->command[0]);
		create_fork(t_pipex->command, t_pipex);
		t_pipex = t_pipex->next;
	}
}
