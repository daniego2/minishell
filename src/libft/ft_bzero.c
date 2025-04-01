/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:28:24 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:11 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes n '\0' to the string s. If n = 0, it does nothing.

void	*ft_bzero(void *str, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)str;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
