/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:10:58 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/01 13:08:37 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

/* void	ft_bzero(void *block, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)block)[i] = 0;
		i++;
	}
} */

/* void	*ft_calloc(size_t n, size_t size)
{
	void	*block;

	block = malloc(n * size);
	if (block == NULL)
		return (NULL);
	ft_bzero(block, n * size);
	return (block);
} */

/* void	ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
} */

/* bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f')
		return (true);
	else
		return (false);
} */

/* bool	ft_strmatch(char *a, char *b)
{
	size_t	i;

	i = 0;
	while (a[i] != 0 && b[i] != 0 && a[i] == b[i])
		i++;
	if (a[i] == b[i])
		return (true);
	else
		return (false);
} */
