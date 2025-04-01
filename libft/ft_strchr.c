/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:25:03 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:29:31 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first "c" occurrence in the "str" string.
// Returns a pointer to the located character.

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != (char)c && *ptr != '\0')
	{
		ptr++;
	}
	if (*ptr == (char)c)
	{
		return (ptr);
	}
	return (NULL);
}
