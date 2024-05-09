/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:13:41 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/06 15:27:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Returns the last node of the list.
/// @param lst 	Beginning of the list.
/// @return 	Last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			return (ptr);
	}
	return (lst);
}
