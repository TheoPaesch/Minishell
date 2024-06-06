/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:54:12 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/03 20:03:13 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Iterates the list ’lst’ and applies the function ’f’ on
///				the data of each node.
/// @param lst 	Address of a pointer to a node.
/// @param f 	Address of the function used to iterate on the list.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		lst = lst->next;
		f(tmp->data);
		tmp = lst;
	}
}
