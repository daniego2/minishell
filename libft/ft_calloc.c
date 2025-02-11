/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:11:12 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:14 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate memory and fills it with '\0'. 
// Returns a ptr to the allocated memory.

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = malloc(count * size);
	i = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
