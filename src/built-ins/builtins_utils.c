#include "minishell.h"

int is_builtin(char *command)
{
	if (ft_strncmp(command, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(command, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(command, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(command, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(command, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(command, "exit", 5) == 0)
		return (1);
	return (0);
}
int is_builtin_pipeless(char *command)
{
	if (ft_strncmp(command, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(command, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(command, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(command, "exit", 5) == 0)
		return (1);
	return (0);
}

int exec_builtin(char **command, t_env **env)
{
	int exit_status;

	exit_status = 0;
	if (ft_strncmp(command[0], "echo", 4) == 0)
		exit_status = exec_echo(command);
	else if (ft_strncmp(command[0], "cd", 2) == 0)
		exit_status = exec_cd(command);
	else if (ft_strncmp(command[0], "pwd", 3) == 0)
		exit_status = exec_pwd();
	else if (ft_strncmp(command[0], "export", 6) == 0)
		exit_status = exec_export(env, command);
	else if (ft_strncmp(command[0], "unset", 5) == 0)
		exit_status = exec_unset(env, command);
	else if (ft_strncmp(command[0], "env", 3) == 0)
		exit_status = exec_env(env);
	else if (ft_strncmp(command[0], "exit", 5) == 0)
		exit_status = 0;
	printf("exit status: %d\n", exit_status);
	return (exit_status);
}
