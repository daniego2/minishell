/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:39:29 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:16:56 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies "len" bytes from "src" to "dest". They may overlap.
// Returns the original value of "dest". 

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*destcast;
	char	*srccast;

	destcast = (char *)dest;
	srccast = (char *)src;
	if (!destcast && !srccast && len)
		return (dest);
	if (destcast < srccast)
	{
		while (len-- > 0)
			*destcast++ = *srccast++;
	}
	else
	{
		destcast += len - 1;
		srccast += len - 1;
		while (len > 0)
		{
			*destcast-- = *srccast--;
			len--;
		}
	}
	return (dest);
}
