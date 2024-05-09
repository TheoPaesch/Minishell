/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:24:39 by mstrauss          #+#    #+#             */
/*   Updated: 2023/10/20 18:30:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Takes as a parameter a node and frees the memory of
///				the node’s content using the function ’del’ given
///				as a parameter and free the node. The memory of
///				’next’ must not be freed.
/// @param lst 	Node to free.
/// @param del 	Address of the function used to delete the content.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
