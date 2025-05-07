/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:33:43 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/07 16:01:39 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	get_out_fd(t_cmd *cmd)
{
	t_redir	*redir;
	int		fd;

	redir = cmd->redir;
	fd = -1;
	while (redir != NULL)
	{
		if (redir->type == REDIR_OUT)
			fd = open(redir->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (redir->type == REDIR_APPEND)
			fd = open(redir->filename, O_CREAT | O_RDWR | O_APPEND, 0644);
		redir = redir->next;
	}
	return (fd);
}

int	get_in_fd(t_cmd *cmd, t_env *env)
{
	t_redir	*redir;
	int		fd;

	redir = cmd->redir;
	fd = -1;
	while (redir != NULL)
	{
		if (redir->type == REDIR_IN)
		{
			fd = open(redir->filename, O_RDONLY);
			if (fd == -1)
			{
				return (-69);
			}
		}
		else if (redir->type == REDIR_HEREDOC)
		{
			fd = here_doc(redir->filename, redir->is_quoted, env);
		}
		redir = redir->next;
	}
	return (fd);
}
