/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:17:32 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/26 16:21:24 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and free the node "lst" and all the consecutives using
// "del" function and free. The pointer to the end of the list is NULL

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst;
	while (aux != NULL)
	{
		temp = aux;
		aux = aux->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
