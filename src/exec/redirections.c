#include "minishell.h"

extern int g_signal;

int delimiter_is_quoted(char *delimiter)
{
	int i;
	int quotes;

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

// Variable expansion logic working. Need to change how im receiving delimiter, as is always unquoted.
static void handle_heredoc_child(int temp_fd, char *delimiter, t_env *env, bool is_quoted)
{
    char *line;

    setup_signal_handlers_hd();
    while (1)
    {
        line = readline("> ");
		if (is_quoted == false)
		{
			line = expand_heredoc_str(line, env, 0);
		}
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

static int handle_heredoc_parent(int pid)
{
    int fd;
    
    waitpid(pid, NULL, 0);
    if (g_signal == SIGINT)
        return (1);
    fd = open("/tmp/.here_doc", O_RDONLY);
    return (fd);
}

int here_doc(char *delimiter, t_env *env)
{
    int temp_fd;
    int pid;

    temp_fd = open("/tmp/.here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("delimiter: %s\n", delimiter);
	if (delimiter_is_quoted(delimiter) == 1)
		printf("minishell: WARNING: here-document delimiter delimited by single quote: You can exit here-doc with ( %s )\n", delimiter);
    pid = fork();
    if (pid == 0)
	{
		if (delimiter_is_quoted(delimiter) == 1 || delimiter_is_quoted(delimiter) == 2)
        	handle_heredoc_child(temp_fd, delimiter, env, true);
		else
			handle_heredoc_child(temp_fd, delimiter, env, false);
	}
    else
    {
        close(temp_fd);
        return (handle_heredoc_parent(pid));
    }
    return (-1);
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

int get_in_fd(t_cmd *cmd, t_env *env)
{
	t_redir *redir;
	int fd;

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
			fd = here_doc(redir->filename, env);
			if (fd == 1)
				g_signal = SIGINT;
		}
		redir = redir->next;
	}
	return (fd);
}
