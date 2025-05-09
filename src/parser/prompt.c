/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:50:34 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/05 15:56:10 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser_types.h"

static int	len(char *s)
{
	return (ft_strlen(s));
}

static void	populate_prompt(char *prompt, t_env *var_a, t_env *var_b,
		struct s_separators s)
{
	ft_memcpy(prompt, "\033[34m", 5);
	if (var_a != NULL)
	{
		ft_memcpy(&prompt[5], var_a->value, len(var_a->value));
		ft_memcpy(&prompt[len(prompt)], s.sep_a, len(s.sep_a));
	}
	if (var_b != NULL)
		ft_memcpy(&prompt[len(prompt)], var_b->value, len(var_b->value));
	ft_memcpy(&prompt[len(prompt)], s.sep_b, len(s.sep_b));
}

char	*get_prompt(t_env **env, char *key_a, char *key_b)
{
	char				*prompt;
	t_env				*var_a;
	t_env				*var_b;
	struct s_separators	s;
	int					prompt_len;

	s.sep_a = "\033[36m ";
	s.sep_b = "\033[31m > \033[0m";
	var_a = get_environment_variable(*env, key_a);
	var_b = get_environment_variable(*env, key_b);
	prompt_len = len(s.sep_a) + len(s.sep_b);
	if (var_a != NULL)
		prompt_len += len(var_a->value);
	if (var_b != NULL)
		prompt_len += len(var_b->value);
	prompt = ft_calloc(5 + prompt_len + 1, sizeof(char));
	if (!prompt)
		exit(1);
	populate_prompt(prompt, var_a, var_b, s);
	return (prompt);
}
