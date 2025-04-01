/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:54:12 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/26 16:17:31 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory for a string that represents the int given.
// Returns a string that represents the number given or NULL if memory fails.

static unsigned int	ft_digit_counter(long n)
{
	int		x;
	long	aux;
	long	digits;

	x = 0;
	aux = n;
	digits = 1;
	if (aux < 0)
	{
		aux = -aux;
		x++;
	}
	while (aux >= 10)
	{
		aux = aux / 10;
		digits++;
	}
	return (digits + x);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = n;
	str = malloc(sizeof(char) * (ft_digit_counter(n)) + 1);
	if (str == NULL)
		return (NULL);
	i = ft_digit_counter(n);
	str[i--] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (str);
}
