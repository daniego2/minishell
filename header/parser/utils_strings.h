/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strings.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:41 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/23 16:24:10 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRINGS_H
# define UTILS_STRINGS_H

int		min(int a, int b);
int		copy_str_n(char *dst, char *src, int n);
char	*clone_str_n(char *str, int n);
char	*cat_str_n_m(char *a, int n, char *b, int m);

#endif
