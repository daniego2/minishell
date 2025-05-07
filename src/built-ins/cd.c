/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:24:58 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/07 21:42:11 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(t_env **env)
{
	char	*path;
	t_env	*pwd;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return ;
	pwd = get_environment_variable(*env, "PWD");
	free(pwd->value);
	pwd->value = ft_strdup(path);
	free(path);
}

int	exec_cd(t_env **env, char **argv)
{
	t_env	*home_node;

	home_node = get_environment_variable(*env, "HOME");
	if (!argv[1])
	{
		if (home_node == NULL)
		{
			printf("minishell: cd: HOME not set\n");
			return (1);
		}
		else
			chdir(home_node->value);
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			printf("minishell: cd: %s: No such file or directory\n", argv[1]);
			return (1);
		}
	}
	update_pwd(env);
	return (0);
}
