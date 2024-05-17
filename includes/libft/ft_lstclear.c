/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:33:58 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/17 16:07:54 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief		Deletes and frees the given node and every successor of that
///				node, using the function ’del’ and free(3). Finally, the pointer
///				to the list must be set to NULL.
/// @param lst 	Address of a pointer to a node.
/// @param del  Address of the function used to delete the data of the node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *lst;
	tmp = ptr;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		ft_lstdelone(tmp, del);
		tmp = ptr;
	}
	*lst = NULL;
}
