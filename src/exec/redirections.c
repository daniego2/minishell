#include "minishell.h"

extern int g_signal;

int here_doc(char *delimiter)
{
    int fd;
    char *line;
    int temp_fd;
    int pid;

    temp_fd = open("/tmp/.here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid = fork();
    if (pid == 0)
    {
        setup_signal_handlers_hd();
        while (1)
        {
            line = readline("> ");
            if (!line)
            {
                printf("minishell: warning: here-document delimited by end-of-file (wanted `%s')\n", delimiter);
                break;
            }
            if (ft_strcmp(line, delimiter) == 0)
            {
                free(line);
                break;
            }
            write(temp_fd, line, ft_strlen(line));
            write(temp_fd, "\n", 1);
            free(line);
        }
        close(temp_fd);
        exit(0);
    }
	else
    {
        close(temp_fd);
        waitpid(pid, NULL, 0);
        if (g_signal == SIGINT)
            return (1);
        fd = open("/tmp/.here_doc", O_RDONLY);
        return (fd);
    }
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
		{
			fd = open(redir->filename, O_RDONLY);
			if (fd == -1)
			{
				printf("minishell: %s: No such file or directory\n", redir->filename);
				return (-69);
			}
		}

		if (redir->type == REDIR_HEREDOC)
		{
			here_doc_fd = here_doc(redir->filename);
			fd = here_doc_fd;
			if (fd == 1000)
			{
				g_signal = SIGINT;
			}
		}
		redir = redir->next;
	}
	return (fd);
}