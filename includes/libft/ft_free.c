/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:07:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/26 15:34:17 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_mem_entry(t_list **lst, void *ptr)
{
	t_list	*tmp;
	t_list	*prev;

	if (lst == NULL || ptr == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	prev = NULL;
	while (tmp != NULL)
	{
		if (tmp->data == ptr)
		{
			if (prev == NULL)
				*lst = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp->data);
			free(tmp);
			return ;
		}
		prev = tmp;
		if (tmp->next == NULL)
			return ;
		tmp = tmp->next;
	}
}

/// @brief
/// @param ptr
/// @return ALWAYS returns Nll in order to enable freeing and nulling in oneline
void	*ft_free(void *ptr)
{
	static t_list	**allocs = NULL;

	if (allocs == NULL && ptr == NULL)
		return (allocs = get_mem_lst(), NULL);
	remove_mem_entry(allocs, ptr);
	return (NULL);
}

/*
EXAMPLE
int	main(void)
{
	void	*ptr;

	ptr = ft_malloc(size);
	ptr = ft_free(ptr);	// ft_free() ALWAYS returns null in order to enable
						// freeing and nulling in one line.
}
*/
