/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:35:41 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:17 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tests if an character is alphanumeric.
// Returns 0 if false and 1 if true.

int	ft_isalnum(int c)
{
	if (((c >= '0') && (c <= '9'))
		|| ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
	{
		return (1);
	}
	return (0);
}
