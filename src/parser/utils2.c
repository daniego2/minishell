/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:38:49 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:47:03 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdbool.h"
#include "stdlib.h"

bool	ft_memmatch(char *a, char *b, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && a[i] != 0 && b[i] != 0)
	{
		if (a[i] == b[i])
		{
			i++;
			continue ;
		}
		else
			return (false);
	}
	return (true);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
