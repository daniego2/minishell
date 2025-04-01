/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:15:41 by daniego2          #+#    #+#             */
/*   Updated: 2023/12/21 19:54:58 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list "lst" and applies the function "f" to every node content.
// It creates a new list with the result. It uses a "del" function if needed.
// Returns the new list.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*newcontent;

	newlst = NULL;
	while (lst != NULL)
	{
		newcontent = f(lst->content);
		if (newcontent == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode = ft_lstnew(newcontent);
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			free(newcontent);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
