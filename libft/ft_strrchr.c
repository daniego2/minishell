/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:53:57 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:45:46 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the last "c" occurrence in the "str" string.
// Returns a pointer to the located character.

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)str;
	while (ptr[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i--;
	}
	return (0);
}
