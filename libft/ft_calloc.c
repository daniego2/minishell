/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:11:12 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/01 13:04:13 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate memory and fills it with '\0'. 
// Returns a ptr to the allocated memory.

void	*ft_calloc(size_t n, size_t size)
{
	void	*block;

	block = malloc(n * size);
	if (block == NULL)
		return (NULL);
	ft_bzero(block, n * size);
	return (block);
}