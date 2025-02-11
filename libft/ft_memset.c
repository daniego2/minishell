/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:27:32 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:20:20 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes "len" bytes with value "c" to string "str"
// Returns the transformed string.

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
}
