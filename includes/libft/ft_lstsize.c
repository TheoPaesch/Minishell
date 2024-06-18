/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:44:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 16:44:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Counts the number of nodes in a list.
/// @param lst 	Beginning of the list.
/// @return 	Length of the list.
int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		i;

	ptr = lst;
	i = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
