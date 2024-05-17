/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/16 19:30:40 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	*ft_malloc(int size, void **ptr)
{
	static t_list	allocs;

	*ptr = malloc(size);
	if (*ptr == NULL)
		return (1);
	if (!allocs)
		allocs = ft_lstnew(ptr);
	else
		ft_lstadd_front(allocs, ft_lstnew(ptr));
	return (*ptr == NULL);
}

/* -------------------------------------------------------------------------- */
/*                                 EXPLANATION                                */
/* -------------------------------------------------------------------------- */
/*

// the pointer that we create in malloc() in order to remember where we allocted
void		*allocated_mem; // internal to malloc()/garbage_collection

typedef struct s_garbage
{
	void			**extern_ptr;  //the ptr/var used in our main thread/program
	void			*allocated_mem;//the actual location of allocated memory
}					t_garbage;



typedef struct s_list
{
	void			*data; // store s_garbage here
	struct s_list	*next;
}					t_list;

*/