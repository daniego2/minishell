/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:08:22 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/01 13:08:32 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strmatch(char *a, char *b)
{
	size_t	i;

	i = 0;
	while (a[i] != 0 && b[i] != 0 && a[i] == b[i])
		i++;
	if (a[i] == b[i])
		return (true);
	else
		return (false);
}

// Check if the "b" string is a substring of "a" in starting at address of "a".
bool	ft_substrmatch(char *a, char *b)
{
	size_t i;

	i = 0;
	while (a[i] != 0 && b[i] != 0 && a[i] == b[i])
		i++;
	if (a[i] == b[i] || b[i] == 0)
		return (true);
	else
		return (false);
}
