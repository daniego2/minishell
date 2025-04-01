/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:29:21 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 20:23:08 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sends the character "c" into the file descriptor "fd"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
