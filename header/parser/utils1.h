/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:12:07 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/27 14:34:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS1_H
# define UTILS1_H
# include <stdbool.h>
# include <stddef.h>

void	ft_bzero(void *block, size_t len);
void	*ft_calloc(size_t n, size_t size);
void	ft_memcpy(void *dst, void *src, size_t n);
bool	ft_isspace(char c);
bool	ft_strmatch(char *a, char *b);
bool	ft_memmatch(char *a, char *b, size_t n);

#endif
