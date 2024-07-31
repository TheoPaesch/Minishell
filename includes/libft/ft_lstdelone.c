/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:24:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/31 13:50:47 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Takes as a parameter a node and frees the memory of
///				the node’s data using the function ’del’ given
///				as a parameter and free the node. The memory of
///				’next’ must not be freed.
/// @param lst 	Node to free.
/// @param del 	Address of the function used to delete the data.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(void)del;
	if (lst != NULL && lst->data != NULL)
	{
		lst->data = ft_free(lst->data);
		lst = NULL;
	}
	if (lst != NULL)
	{
		free(lst);
	}
}
