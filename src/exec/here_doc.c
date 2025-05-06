/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:06:09 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 18:16:54 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	delimiter_is_quoted(char *delimiter)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (delimiter[i])
	{
		if (delimiter[i] == '\'' || delimiter[i] == '\"')
		{
			quotes++;
			if (quotes == 2)
				return (2);
		}
		i++;
	}
	if (quotes == 1)
	{
		return (1);
	}
	return (0);
}

void	handle_heredoc_child(int temp_fd, char *delimiter, t_env *env,
		bool is_quoted)
{
	char	*line;

	setup_signal_handlers_hd();
	g_signal = -1;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("minishell: warning: here-document delimited by "
				"end-of-file (wanted `%s')\n", delimiter);
			break ;
		}
		if (is_quoted == 0)
			line = expand_heredoc_str(line, env, 0);
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(temp_fd, line, ft_strlen(line));
		write(temp_fd, "\n", 1);
		free(line);
	}
	close(temp_fd);
	exit(0);
}

int	handle_heredoc_parent(int pid)
{
	int	fd;
	int result;

	waitpid(pid, &result, 0);
	if (WIFEXITED(result))
		return (6969);
	if (g_signal == SIGINT)
	{	
		return (1);
	}
	fd = open("/tmp/.here_doc", O_RDONLY);
	return (fd);
}

int	here_doc(char *delimiter, bool is_quoted, t_env *env)
{
	int	temp_fd;
	int	pid;

	temp_fd = open("/tmp/.here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (delimiter_is_quoted(delimiter) == 1)
		printf("minishell: WARNING: here-document delimiter delimited by single quote: You can exit here-doc with ( %s )\n", delimiter);
	pid = fork();
	if (pid == 0)
	{
		handle_heredoc_child(temp_fd, delimiter, env, is_quoted);
	}
	else
	{
		close(temp_fd);
		return (handle_heredoc_parent(pid));
	}
	return (-1);
}