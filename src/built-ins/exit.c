/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:24:45 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/08 13:02:41 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(const char *str)
{
	int	len;
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	len = 0;
	while (str[i + len] >= '0' && str[i + len] <= '9')
		len++;
	if (len > 19)
		return (1);
	if (len == 19)
	{
		if (ft_strncmp(str + i, "9223372036854775807", 19) > 0)
			return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	exec_exit(char **command)
{
	long	exit_status;

	printf("exit\n");
	if (!command[1])
		return (0);
	if (!ft_strisnum(command[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", command[1]);
		return (255);
	}
	if (is_overflow(command[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", command[1]);
		return (2);
	}
	exit_status = ft_atol(command[1]);
	if (command[2])
	{
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	return ((unsigned char)exit_status);
}

int	check_exit(t_cmd *cmd, t_env **env, int exit_status)
{
	int	status;

	if (cmd->in_fd != STDIN_FILENO && cmd->next != NULL)
		return (exit_status);
	else
	{
		if (cmd->command[1] && cmd->command[2])
		{
			printf("minishell: exit: too many arguments\n");
			return (1);
		}
		status = exec_exit(cmd->command);
		print_among_us(status);
		free_pipeline(cmd);
		free_env(*env);
		exit(status);
	}
}
