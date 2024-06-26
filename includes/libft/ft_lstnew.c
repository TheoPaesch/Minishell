/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:57 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/14 18:01:31 by mstrauss         ###   ########.fr       */
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

	sl1 = ft_malloc(sizeof(t_list));
	if (sl1 == NULL)
	{
		printf("ft_lstnew failed.\n");
		exit(1);
	}
	sl1->data = data;
	sl1->next = NULL;
	return (sl1);
}
