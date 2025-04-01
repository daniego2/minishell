/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:25:57 by daniego2          #+#    #+#             */
/*   Updated: 2025/01/29 17:15:29 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes all "set" characters from beginning and ending of the string "s1"
// until it finds a non-belonging character of "set"
// Returns and malloc the resulted string

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1) - 1;
	if (!s1[0])
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]) && (i <= len))
		i++;
	if (i > len)
		return (ft_strdup(len + s1 + 1));
	while ((ft_strchr(set, s1[len]) && (len > 0)))
		len--;
	ptr = malloc(sizeof(char) * (len - i + 2));
	if (ptr == NULL)
		return (NULL);
	s1 = s1 + i;
	ft_strlcpy(ptr, s1, len - i + 2);
	return (ptr);
}
