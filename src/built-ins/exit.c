/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:24:45 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/02 17:18:35 by daniego2         ###   ########.fr       */
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