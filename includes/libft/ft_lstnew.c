/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:57 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/29 11:05:05 by tpaesch          ###   ########.fr       */
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

	printf("reached lstnew here\n");
	sl1 = NULL;
	if (!ft_malloc(sl1, sizeof(t_list)))
		exit(1);
	sl1->content = data;
	sl1->next = NULL;
	return (sl1);
}
