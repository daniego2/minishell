/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:58:35 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:44:56 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first ocurrence of "needle" in "haystack" in less than "len" char
// Returns a pointer to the first occurrence if it occurs.
// Returns NULL if it doesnt occurs.
// Returns "haystack" if "needle" is empty

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return (h);
	while (h[i] != '\0' && i < len)
	{
		while ((n[j] == h[i + j]) && (i + j < len))
		{
			j++;
			if (n[j] == '\0')
			{
				return (&h[i]);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
