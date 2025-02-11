/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:16:24 by daniego2          #+#    #+#             */
/*   Updated: 2025/02/05 17:09:55 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares "s1" against "s2" until it finds a difference, in less than "n" char
// Returns 0 if equal, or the diference between both.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	counter;
	unsigned char	*p1;
	unsigned char	*p2;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < (n - 1) && p1[counter] != '\0' && p2[counter] != '\0')
	{
		if (p1[counter] != p2[counter])
			return (p1[counter] - p2[counter]);
		counter++;
	}
	return (p1[counter] - p2[counter]);
}
