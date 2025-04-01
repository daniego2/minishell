/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:26:40 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:22:28 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

static void	remove_quote_pair(char *str, int idx_a, int idx_b)
{
	int	i;

	i = idx_a;
	while (i + 1 < idx_b && str[i + 1] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
	if (str[i + 1] == '\0')
	{
		str[i] = '\0';
		return ;
	}
	while (str[i + 2] != '\0')
	{
		str[i] = str[i + 2];
		i++;
	}
	if (str[i + 2] == '\0')
		str[i] = '\0';
}

static int	find_matching_pair_on_str(char *str)
{
	char	c;
	int		i;
	char	original_c;

	original_c = str[0];
	i = 1;
	c = str[i];
	while (c != 0 && c != original_c)
	{
		i++;
		c = str[i];
	}
	if (c == original_c)
		return (i);
	else
		return (0);
}

t_token	*clean_up_quotes(t_token *token)
{
	int	i;
	int	pair_idx;

	i = 0;
	while (token->str[i] != 0)
	{
		if (token->str[i] == '\'' || token->str[i] == '\"')
		{
			pair_idx = i + find_matching_pair_on_str(&(token->str[i]));
			if (pair_idx != i)
			{
				remove_quote_pair(token->str, i, pair_idx);
				i = pair_idx - 1;
				continue ;
			}
		}
		i++;
	}
	return (token);
}
