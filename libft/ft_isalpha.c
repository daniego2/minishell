/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:45 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 18:54:33 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tests if an character is alphabetic.
// Returns 0 if false and 1 if true.

int	ft_isalpha(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (1);
	}
	if ((c >= 'a') && (c <= 'z'))
	{
		return (2);
	}
	return (0);
}
