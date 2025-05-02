#include "minishell.h"

int is_builtin(char *command)
{
	if (command == NULL)
		return (0);
	if (ft_strcmp(command, "echo") == 0)
		return (1);
	else if (ft_strcmp(command, "cd") == 0)
		return (1);
	else if (ft_strcmp(command, "pwd") == 0)
		return (1);
	else if (ft_strcmp(command, "export") == 0)
		return (1);
	else if (ft_strcmp(command, "unset") == 0)
		return (1);
	else if (ft_strcmp(command, "env") == 0)
		return (1);
	else if (ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}
int is_builtin_pipeless(char *command)
{
	if (command == NULL)
		return (0);
	if (ft_strcmp(command, "cd") == 0)
		return (1);
	else if (ft_strcmp(command, "export") == 0)
		return (1);
	else if (ft_strcmp(command, "unset") == 0)
		return (1);
	else if (ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

int exec_builtin(t_cmd *cmd, t_env **env, int exit_status)
{	
	if (ft_strcmp(cmd->command[0], "echo") == 0)
		exit_status = exec_echo(cmd->command, exit_status);
	else if (ft_strcmp(cmd->command[0], "cd") == 0)
		exit_status = exec_cd(env, cmd->command);
	else if (ft_strcmp(cmd->command[0], "pwd") == 0)
		exit_status = exec_pwd();
	else if (ft_strcmp(cmd->command[0], "export") == 0)
		exit_status = exec_export(env, cmd->command);
	else if (ft_strcmp(cmd->command[0], "unset") == 0)
		exit_status = exec_unset(env, cmd->command);
	else if (ft_strcmp(cmd->command[0], "env") == 0)
		exit_status = exec_env(*env);
	else if (ft_strcmp(cmd->command[0], "exit") == 0)
	{
		if (cmd->in_fd != STDIN_FILENO && cmd->next != NULL)
			return (exit_status);
		else
			exit_status = exec_exit(cmd->command);
	}
	return (exit_status);
}
