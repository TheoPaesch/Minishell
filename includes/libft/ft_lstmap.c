/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:56:30 by mstrauss          #+#    #+#             */
/*   Updated: 2023/10/20 22:37:28 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Iterates the list ’lst’ and applies the function ’f’ on the
///				content of each node. Creates a new list resulting of the
///				successive applications of the function ’f’. The ’del’ function
///				is used to delete the content of a node if needed.
/// @param lst 	Address of a pointer to a node.
/// @param f 	Address of the function used to iterate on the list.
/// @param del 	The address of the function used to delete
///				the content of a node if needed.
/// @return 	The new list. NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*lstnext;
	void	*data;

	lstnext = NULL;
	if (lst == NULL)
		return (NULL);
	lstnext = ft_lstmap(lst->next, *f, *del);
	data = f(lst->content);
	lstnew = ft_lstnew(data);
	if (lstnew == NULL)
	{
		del(data);
		ft_lstclear(&lstnext, del);
		return (NULL);
	}
	lstnew->next = lstnext;
	return (lstnew);
}
