/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:27:26 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:09 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts the initial portion of the string pointed to by str to int.
// Returns an int.

int	ft_atoi(const char *str)
{
	int	i;
	int	dig;
	int	sign;

	dig = 0;
	i = 0;
	sign = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		dig = dig + (str[i] - '0');
		if ((str[i + 1] >= '0') && (str[i + 1] <= '9'))
			dig = dig * 10;
		i++;
	}
	return (dig * sign);
}
