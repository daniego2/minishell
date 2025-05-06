/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:24:55 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 19:02:44 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_flag(char *argv)
{
	int	j;

	j = 1;
	while (argv[j])
	{
		if (argv[j] != 'n')
		{
			return (false);
		}
		j++;
	}
	return (true);
}

int	exec_echo(char **argv)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (ft_strncmp(argv[i], "-n", 2) == 0)
	{
		if (is_valid_flag(argv[i]))
			newline = 0;
		else
			break ;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (newline > 0)
		printf("\n");
	return (0);
}
