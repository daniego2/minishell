/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:24:45 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 16:24:30 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_exit(char **command)
{

	if (command[1] && !command[2])
		return(ft_atoi(command[1]));
	else if (!command[1])
		return(0);
	else
		printf("minishell: exit: too many arguments\n");
	return(1);
}

int check_exit(t_cmd *cmd, t_env **env, int exit_status)
{
	if (cmd->in_fd != STDIN_FILENO && cmd->next != NULL)
		return (exit_status);
	else
	{
		exit_status = exec_exit(cmd->command);
		free_pipeline(cmd);
		free_env(*env);
		print_among_us(exit_status);
		exit(exit_status);
	}
}
