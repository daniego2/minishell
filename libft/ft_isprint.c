/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:01:32 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 18:56:01 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tests if an character is printable.
// Returns 0 if false and 1 if true.

int	ft_isprint(int c)
{
	if ((c >= ' ') && (c <= '~'))
	{
		return (1);
	}
	return (0);
}
