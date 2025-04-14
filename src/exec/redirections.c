#include "minishell.h"

int here_doc(char *filename)
{
	int fd;
	char *line;
	int temp_fd;

	temp_fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	line = readline("> ");
	while (line != NULL)
	{
		if (strcmp(line, filename) == 0)
		{
			break;
		}
		write(temp_fd, line, ft_strlen(line));
        write(temp_fd, "\n", 1);
		line = readline("> ");
	}
    close(temp_fd);
	fd = open(".here_doc", O_RDONLY);
    return (fd);
}

int get_out_fd(t_cmd *cmd)
{
    t_redir *redir;
    int fd;

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

int get_in_fd(t_cmd *cmd)
{
	t_redir *redir;
	int fd;
	int here_doc_fd;

	redir = cmd->redir;
	fd = -1;
	while (redir != NULL)
	{
		if (redir->type == REDIR_IN)
			fd = open(redir->filename, O_RDONLY);
		if (redir->type == REDIR_HEREDOC)
		{
			here_doc_fd = here_doc(redir->filename);
			fd = here_doc_fd;
		}
		redir = redir->next;
	}
	return (fd);
}