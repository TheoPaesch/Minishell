/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:57 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/25 17:07:50 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 	Allocates (with malloc(3)) and returns a new node.
///			The member variable ’data’ is initialized with
///			the value of the parameter ’data’. The variable
///			’next’ is initialized to NULL.
/// @param data 	The data to create the node with.
/// @return			The new node.
t_list	*ft_lstnew(void *data)
{
	t_list	*sl1;

	sl1 = NULL;
	ft_malloc(sl1, sizeof(t_list));
	if (sl1 == NULL)
		return (0);
	sl1->content = data;
	sl1->next = NULL;
	return (sl1);
}
