/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:41 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/07 12:49:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	copy_str_n(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

char	*clone_str_n(char *str, int n)
{
	char	*new_str;

	new_str = ft_calloc(n + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	copy_str_n(new_str, str, n);
	return (new_str);
}

char	*cat_str_n_m(char *a, int n, char *b, int m)
{
	char	*new_str;
	int		bytes_copied;

	new_str = ft_calloc(n + m + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	bytes_copied = copy_str_n(new_str, a, n);
	copy_str_n(&new_str[min(n, bytes_copied)], b, m);
	return (new_str);
}
