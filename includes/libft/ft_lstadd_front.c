/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:33:44 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/15 00:41:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Adds the node ’new’ at the beginning of the list.
/// @param lst 	Address of a pointer to the first link of a list.
/// @param new 	Address of a pointer to the node to be added to the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
	{
		ft_putstr_fd("ERROR IN LSTADDFRONT. RECEIVED NULL INSTEAD OF NODE\n",
			2);
		return ;
	}
	new->next = *lst;
	*lst = new;
}
