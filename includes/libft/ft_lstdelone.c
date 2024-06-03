/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:24:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/27 14:50:42 by tpaesch          ###   ########.fr       */
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
	del(lst->content);
	ft_free(&lst);
}
