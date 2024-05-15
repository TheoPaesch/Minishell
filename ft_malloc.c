/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/15 16:57:46 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_malloc(int size)
{
	void			*tmp;
	static t_list	allocs;

	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	if (!allocs)
		allocs = ft_lstnew(tmp);
	else
		ft_lstadd_front(allocs, ft_lstnew(tmp));
	return (tmp);
}
