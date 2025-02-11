/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:45:58 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:30:36 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates enough memory for a copy of the str "s1" and does a copy.
// Returns a pointer to the copy

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	s1 = (char *)s1;
	i = 0;
	ptr = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
