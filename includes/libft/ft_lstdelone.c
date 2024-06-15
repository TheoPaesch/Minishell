/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:24:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/15 01:06:15 by mstrauss         ###   ########.fr       */
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
	if (lst != NULL)
	{
		del(lst->data);
		ft_free(lst);
		lst = NULL; // dbg, maybe change back
	}
}
