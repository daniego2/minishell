/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:24:45 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/01 20:47:16 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_exit(char **command)
{

	if (command[1] && !command[2])
	{
		printf("sale con %s\n", command[1]);
		exit(ft_atoi(command[1]));
	}

	else if (!command[1])
	{
		printf("sale con 0\n");
		exit(0);
	}
	else
	{
		printf("minishell: exit: too many arguments\n");
		return(1);
	}
}