/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:09:32 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:49:56 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

// Allocates with malloc and creates a substring from the string "s" that 
// starts in "start" and has a lenght of "len"
// Returns the new substring

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(len * sizeof(char) + 1);
	i = start;
	j = 0;
	if ((ptr == NULL) || (s == (void *)0))
		return (NULL);
	while ((j < len) && (s[i] != '\0'))
	{
		ptr[j] = s[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
