/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:30:33 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/07 12:33:17 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokenizer	*init_tokenizer(void)
{
	t_tokenizer	*tokenizer;

	tokenizer = ft_calloc(1, sizeof(t_tokenizer));
	if (!tokenizer)
		exit(EXIT_FAILURE);
	tokenizer->text = NULL;
	return (tokenizer);
}
