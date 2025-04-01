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

int get_out_fd(t_token *token)
{
    t_redir *redir;
    int fd;

    redir = token->redir;
    fd = -1;
    while (redir != NULL)
    {
        if (redir->type == OUT)
            fd = open(redir->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (redir->type == OUTT)
            fd = open(redir->filename, O_CREAT | O_RDWR | O_APPEND, 0644);
        redir = redir->next;
    }
    return (fd);
}

int get_in_fd(t_token *token)
{
	t_redir *redir;
	int fd;
	int here_doc_fd;

	redir = token->redir;
	fd = -1;
	while (redir != NULL)
	{
		if (redir->type == IN)
			fd = open(redir->filename, O_RDONLY);
		if (redir->type == INN)
		{
			here_doc_fd = here_doc(redir->filename);
			fd = here_doc_fd;
		}
		redir = redir->next;
	}
	return (fd);
}